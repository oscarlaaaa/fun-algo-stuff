## 2022-10-16 (O(n) visit, O(1) others)
class BrowserHistory:
    def __init__(self, homepage: str):
        self._sites_visited = [homepage]
        self._current_site = 0
    
    def visit(self, url: str) -> None:
        # clear forward history
        if len(self._sites_visited)-self._current_site-1 >= 1:
            del self._sites_visited[self._current_site+1:]

        # add new url into the history
        self._sites_visited.append(url)

        # make current site the new url
        self._current_site += 1
        
    def back(self, steps: int) -> str:
        # we don't have enough steps to go back, so go back to homepage
        if steps > self._current_site:
            self._current_site = 0
        else:
            self._current_site -= steps
        return self._sites_visited[self._current_site]
        
    def forward(self, steps: int) -> str:
        # we don't have enough steps to go forward, so go to last possible page 
        if steps > len(self._sites_visited) - self._current_site - 1:
            self._current_site = len(self._sites_visited)-1
        else:
            self._current_site += steps
        return self._sites_visited[self._current_site]
        
## 2022-10-16 (O(1) all operations)
#
# Utilizes a variable to keep track of an artificial _sites_visited length
# so that we don't have to delete forward sites when we visit a new site
#
class BrowserHistory:
    def __init__(self, homepage: str):
        self._sites_visited = [homepage]
        self._current_site = 0      # current site
        self._forward_limit = 0     # how far forward we can go
    
    def visit(self, url: str) -> None:
        # clear forward history
        self._forward_limit = self._current_site+1
        
        # add new url into the history
        if self._forward_limit >= len(self._sites_visited):
            self._sites_visited.append(url)
        else:
            self._sites_visited[self._forward_limit] = url

        # make current site the new url
        self._current_site = self._forward_limit
        
    def back(self, steps: int) -> str:
        # we don't have enough steps to go back, so go back to homepage
        if steps > self._current_site:
            self._current_site = 0
        else:
            self._current_site -= steps
        return self._sites_visited[self._current_site]
        
    def forward(self, steps: int) -> str:
        # we don't have enough steps to go forward, so go to last possible page 
        if steps > self._forward_limit - self._current_site:
            self._current_site = self._forward_limit
        else:
            self._current_site += steps
        return self._sites_visited[self._current_site]
        
# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)