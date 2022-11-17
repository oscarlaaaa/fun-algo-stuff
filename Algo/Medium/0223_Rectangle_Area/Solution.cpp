// 2022-11-16
class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        /*
        input: rectangle 1 bottom-left, top-right, then rectangle 2 bottom-left, top-right
        output: total area they overlap on

        approach:
        - find out the length that they vertically intersect
            - if (max(ay1, by1) <= min(ay2, by2)) then they intersect
            - min(ay2, by2) - max(ay1, by1)
        - find out the length that they horizontally intersect
            - if (max(ax1, bx1) <= min(ax2, bx2)) then they intersect
            - min(ax2, bx2) - max(ax1, bx1)
        - multiply together to get intersecting area
        - add areas for both rectangles, then subtract the intersecting
        */
        int verticalIntersect = min(ay2, by2)-max(ay1,by1);
        int horizontalIntersect = min(ax2, bx2)-max(ax1,bx1);

        // if either intersect value is negative, it means they arent overlapping
        int overlapping = 0;
        if (verticalIntersect > 0 && horizontalIntersect > 0)
            overlapping = verticalIntersect * horizontalIntersect;
        
        int rectangleA = (ay2-ay1)*(ax2-ax1);
        int rectangleB = (by2-by1)*(bx2-bx1);

        return rectangleA + rectangleB - overlapping;
    }
};