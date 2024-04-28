import java.util.*;
import java.util.stream.Collectors;

public class LargestNumbers_03 {

            private static int[] kLargestElementFun(int[] arr, int k) {

                PriorityQueue<Integer> minHeap = new PriorityQueue<>();

                for (int i = 0; i < k; i++) {
                    minHeap.offer(arr[i]);
                }

                for (int i = k; i < arr.length; i++) {
                    int currentElement = arr[i];


                    if (currentElement > minHeap.peek()) {

                        minHeap.poll();
                        minHeap.offer(currentElement);
                    }
                }

                int[] result = new int[k];

                for (int i = 0; i < k; i++) {
                    result[i] = minHeap.poll();
                }

                return result;
            }

            public static void main(String[] args) {
                Scanner scanner = new Scanner(System.in);
                int[] myArray = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                int k = Integer.parseInt(scanner.nextLine());

                int[] result = kLargestElementFun(myArray, k);


                for (int element : result) {
                    System.out.println(element);
                }
            }
}
