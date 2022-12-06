class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val = 0, left = nil, right = nil)
        @val = val
        @left = left
        @right = right
    end
end

@param {TreeNode} root
@param {Integer} target_sum
@return {Boolean}
def has_path_sum(root, target_sum)
    if root == nil
        return false;
    end
    
    target_sum -= root.val
    
    if root.left == nil and root.right == nil
        return target_sum == 0
    end
    
    return (has_path_sum(root.left, target_sum) or has_path_sum(root.right, target_sum))
end