## 2023-03-17
class Trie:
    """
    notes:
    - pretty much making a tree where each node of the tree represents
      a letter and then branching off to other letters if they exist?
        - also need to mark whether there is a word that ends there
    - insert follows the chain of nodes and/or creates them if they don't
      exist
    - search follows the chain and sees if the last letter node exists and
      marks the end of a word
    - startswith just checks if the path exists

    analysis:
    - time: all are O(n) where n=length of input
    """
    class TrieNode:
        def __init__(self, is_word):
            self.is_word = is_word
            self.next = dict()

    def __init__(self):
        self.start = Trie.TrieNode(False)

    def insert(self, word: str) -> None:
        current = self.start
        for c in word:
            # create if next node doesn't exist
            if c not in current.next:
                current.next[c] = Trie.TrieNode(False)
            current = current.next[c]
        current.is_word = True

    def search(self, word: str) -> bool:
        current = self.start
        for c in word:
            if c not in current.next:
                return False
            current = current.next[c]
        return current.is_word

    def startsWith(self, prefix: str) -> bool:
        current = self.start
        for c in prefix:
            if c not in current.next:
                return False
            current = current.next[c]
        return True
        
# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)