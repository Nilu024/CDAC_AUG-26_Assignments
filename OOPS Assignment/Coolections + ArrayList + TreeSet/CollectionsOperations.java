import java.util.ArrayList;
import java.util.Collections;

public class CollectionsOperations {

	public static void main(String[] args) {
		
		ArrayList<String> fruits = new ArrayList<String>();
		
		fruits.add("Orange");
		fruits.add("Apple");
		fruits.add("Mango");
		fruits.add("Banana");
		System.out.println("Original: " + fruits);
		
		Collections.sort(fruits);
		System.out.println("Sorted: " + fruits);

		ArrayList<String> fruit = new ArrayList<String>();
		fruit.add("");
		fruit.add("");
		fruit.add("");
		fruit.add("");
		Collections.copy(fruit, fruits);
		System.out.println("Copied: " + fruit);
		
		Collections.shuffle(fruit);
		System.out.println("Shuffled: " + fruit);
		
		Collections.reverse(fruit);
		System.out.println("Reversed: " + fruit);
		
	}

}
