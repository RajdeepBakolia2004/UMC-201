import com.thealgorithms.datastructures.trees.SplayTree;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

public class main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Step 1: Get user inputs for n, m, and c
        System.out.print("Enter the number of distinct values (n): ");
        int n = scanner.nextInt();

        System.out.print("Enter the number of queries (m): ");
        int m = scanner.nextInt();

        System.out.print("Enter the constant c (0 < c < 1): ");
        double c = scanner.nextDouble();
        
        // Validate input for c
        if (c <= 0 || c >= 1) {
            System.out.println("c must be between 0 and 1.");
            return;
        }
        
        // Initialize the splay tree and populate it with n distinct numbers
        SplayTree splayTree = new SplayTree();
        List<Integer> values = new ArrayList<>();
        
        // Step 2: Generate n distinct random numbers and add to tree
        Random random = new Random();
        while (values.size() < n) {
            int value = random.nextInt(n * 10) + 1;  // Ensures wide range to avoid duplicates
            
            // Only insert if not already in tree
            if (!values.contains(value)) {
                values.add(value);
                splayTree.insert(value);
            }
        }

        //System.out.println("Randomly generated values: " + values);

        // Step 3: Select a target number to perform c * m queries
        int targetValue = values.get(random.nextInt(values.size()));
        System.out.println("Target value for frequent queries: " + targetValue);

        // Calculate the number of times we will query the target number
        int targetQueries = (int) (c * m);

        // Step 4: Measure the time taken for a single target query
        long startTime = System.nanoTime();
        splayTree.search(targetValue);  // Only search once
        long endTime = System.nanoTime();

        long timeForSingleQuery = endTime - startTime;
        System.out.println("Time taken for single target query: " + timeForSingleQuery / 1_000_000.0 + " milliseconds");

        // Step 5: Write the result to a text file
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt", true))) {
            writer.append("n: " + n + ", m: " + m + ", c: " + c + ", Time for Single Target Query: " + timeForSingleQuery / 1_000_000.0 + " ms\n");
        } catch (IOException e) {
            System.out.println("Error writing to file: " + e.getMessage());
        }
    }
}
