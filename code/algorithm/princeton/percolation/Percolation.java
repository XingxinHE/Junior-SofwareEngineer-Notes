/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.WeightedQuickUnionUF;

public class Percolation {

    private boolean[] site;
    private WeightedQuickUnionUF helper;

    private int numOpen = 0;

    private int squareLength;

    private int virtualTopSite;
    private int virtualBottomSite;

    private int[][] directions = new int[][] {
            { 0, 1 },  // right
            { -1, 0 }, // top
            { 0, -1 }, // left
            { 1, 0 }   // bottom
    };

    // creates n-by-n grid, with all sites initially blocked
    public Percolation(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("n must be greater than 0.");
        }
        squareLength = n;
        final int size = n * n + 2;
        virtualTopSite = 0;
        virtualBottomSite = n * n + 1;
        site = new boolean[size];
        helper = new WeightedQuickUnionUF(size);
    }

    private boolean isInGrid(int row, int col) {
        return (0 < row && row <= squareLength) && (0 < col && col <= squareLength);
    }

    private boolean isConnected(int p, int q) {
        return helper.find(p) == helper.find(q);
    }

    private int gridToSiteIndex(int row, int col) {
        return (row - 1) * squareLength + col;
    }

    private boolean isTopRow(int row) {
        return row == 1;
    }

    private boolean isBottomRow(int row) {
        return row == squareLength;
    }

    private void traverse(int row, int col) {
        final int newOpenSiteIndex = gridToSiteIndex(row, col);
        // iterate over the 4 directions
        for (int[] direction : directions) {
            int traverseRow = row + direction[0];
            int traverseCol = col + direction[1];
            // check if the new position is within the grid
            if (isInGrid(traverseRow, traverseCol) && isOpen(traverseRow, traverseCol)) {
                // if it is open, union
                helper.union(newOpenSiteIndex, gridToSiteIndex(traverseRow, traverseCol));
            }
        }
    }

    // opens the site (row, col) if it is not open already
    public void open(int row, int col) {
        if (!isInGrid(row, col)) {
            throw new IllegalArgumentException("row or col is out of range.");
        }
        final int siteIndex = gridToSiteIndex(row, col);
        // if it is already open, return
        if (site[siteIndex]) {
            return;
        }

        site[siteIndex] = true;
        numOpen++;

        // if it is either top row or bot row, it has to connect the virtual
        if (isTopRow(row)) {
            helper.union(virtualTopSite, siteIndex);
        }
        // if (isBottomRow(row)) {
        //     helper.union(virtualBottomSite, siteIndex);
        // }

        traverse(row, col);
    }

    // is the site (row, col) open?
    public boolean isOpen(int row, int col) {
        if (!isInGrid(row, col)) {
            throw new IllegalArgumentException("row or col is out of range.");
        }
        return site[gridToSiteIndex(row, col)];
    }

    // is the site (row, col) full?
    public boolean isFull(int row, int col) {
        if (!isInGrid(row, col)) {
            throw new IllegalArgumentException("row or col is out of range.");
        }

        if (!isOpen(row, col)) {
            return false;
        }
        final int siteIndex = gridToSiteIndex(row, col);
        return isConnected(virtualTopSite, siteIndex);
    }

    // returns the number of open sites
    public int numberOfOpenSites() {
        return numOpen;
    }

    // does the system percolate?
    public boolean percolates() {
        return isConnected(virtualTopSite, virtualBottomSite);
    }

    public static void main(String[] args) {
    }
}
