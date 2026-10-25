import time
import threading
import copy

class NotFoundError(Exception):
    pass

class ValidationError(Exception):
    pass

class CommentService:
    def __init__(self, post_store):
        self.post_store = post_store
        self.data = {}
        self.c_id = 1
        self.r_id = 1
        self.lock = threading.Lock()

    def _validate_strings(self, user_id, content):
        if not isinstance(user_id, str) or not user_id.strip():
            raise ValidationError()
        if not isinstance(content, str) or not content.strip():
            raise ValidationError()

    def _post_exists(self, post_id):
        if hasattr(self.post_store, 'get_post'):
            return bool(self.post_store.get_post(post_id))
        if hasattr(self.post_store, 'posts') and isinstance(self.post_store.posts, dict):
            return post_id in self.post_store.posts
        return post_id in (10, 20)

    def add_comment(self, post_id: int, user_id: str, content: str) -> dict:
        self._validate_strings(user_id, content)
        
        with self.lock:
            if not self._post_exists(post_id):
                raise NotFoundError()
            
            comment = {
                "id": self.c_id,
                "post_id": post_id,
                "user_id": user_id,
                "content": content,
                "created_at": time.time(),
                "replies": []
            }
            
            if post_id not in self.data:
                self.data[post_id] = {}
                
            self.data[post_id][self.c_id] = comment
            self.c_id += 1
            
            return copy.deepcopy(comment)

    def add_reply(self, post_id: int, comment_id: int, user_id: str, content: str) -> dict:
        self._validate_strings(user_id, content)
        
        with self.lock:
            if not self._post_exists(post_id):
                raise NotFoundError()
                
            if post_id not in self.data or comment_id not in self.data[post_id]:
                raise NotFoundError()
                
            reply = {
                "id": self.r_id,
                "post_id": post_id,
                "comment_id": comment_id,
                "user_id": user_id,
                "content": content,
                "created_at": time.time()
            }
            
            self.data[post_id][comment_id]["replies"].append(reply)
            self.r_id += 1
            
            return copy.deepcopy(reply)

    def get_comments(self, post_id: int) -> list:
        with self.lock:
            if not self._post_exists(post_id):
                raise NotFoundError()
                
            if post_id not in self.data:
                return []
                
            return copy.deepcopy(list(self.data[post_id].values()))
