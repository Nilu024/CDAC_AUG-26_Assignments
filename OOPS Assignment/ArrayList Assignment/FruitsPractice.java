import java.util.ArrayList;

public class FruitsPractice {

	public static void main(String[] args) {
		
		ArrayList<String> fruits = new ArrayList<String>();
		
		fruits.add("Apple");
		fruits.add("Banana");
		fruits.add("Mango");
		fruits.add("Orange");
		
		System.out.println(fruits.get(1));

		fruits.set(1, "Grapes");
		fruits.remove(1);
		System.out.println(fruits);
		
		fruits.add(0, "Grapes");
		System.out.println(fruits);
		
		System.out.println(fruits.contains("Mango") ? "Found" : "Not Found");
		
	}

}
