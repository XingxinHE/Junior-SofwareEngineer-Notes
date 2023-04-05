/* *****************************************************************************
 *  Name:              Alan Turing
 *  Coursera User ID:  123456
 *  Last modified:     1/1/2019
 **************************************************************************** */

import edu.princeton.cs.algs4.StdRandom;
import edu.princeton.cs.algs4.StdStats;

public class PercolationStats {

    private int sampleSize;
    private int squareLength;

    private double[] threshold;

    private int[] choices;


    // perform independent trials on an n-by-n grid
    public PercolationStats(int n, int trials) {
        if (n <= 0 || trials <= 0) {
            throw new IllegalArgumentException("Invalid arguments.");
        }

        sampleSize = trials;
        threshold = new double[sampleSize];

        squareLength = n;
        final int numSites = n * n;
        choices = new int[numSites];
        for (int i = 0; i < numSites; i++) {
            choices[i] = i + 1;
        }

        for (int ii = 0; ii < trials; ++ii) {
            threshold[ii] = stepAtPercolate(n) / (double) numSites;
        }

    }

    private int stepAtPercolate(int n) {
        Percolation p = new Percolation(n);
        StdRandom.shuffle(choices);

        int choiceIndex = 0;
        while (!p.percolates()) {
            final int row = integerToRow(choices[choiceIndex]);
            final int col = integerToCol(choices[choiceIndex]);
            p.open(row, col);
            ++choiceIndex;
        }
        return choiceIndex + 1;
    }

    private int integerToRow(int integer) {
        return (integer - 1) / squareLength + 1;
    }

    private int integerToCol(int integer) {
        return (integer - 1) % squareLength + 1;
    }

    // sample mean of percolation threshold
    public double mean() {
        return StdStats.mean(threshold);
    }

    // sample standard deviation of percolation threshold
    public double stddev() {
        return StdStats.stddev(threshold);
    }

    // low endpoint of 95% confidence interval
    public double confidenceLo() {
        return mean() - 0.95 * (stddev() / Math.sqrt(sampleSize));
    }

    // high endpoint of 95% confidence interval
    public double confidenceHi() {
        return mean() + 0.95 * (stddev() / Math.sqrt(sampleSize));
    }

    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int t = Integer.parseInt(args[1]);
        PercolationStats stats = new PercolationStats(n, t);
        System.out.println("mean                    = " + stats.mean());
        System.out.println("stddev                  = " + stats.stddev());
        System.out.println(
                "95% confidence interval = [" + stats.confidenceLo() + ", " + stats.confidenceHi()
                        + "]");
    }
}
