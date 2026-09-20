import java.util.TreeSet;

public class TreeSetOperations {

	public static void main(String[] args) {
		
		TreeSet<String> color = new TreeSet<String>();
		
		color.add("Red");
		color.add("Blue");
		color.add("Yellow");
		color.add("Green");
		System.out.println("Original: " + color);
		
		TreeSet<String> colUnique = new TreeSet<String>();
		colUnique.addAll(color);
		System.out.println("Copied: " + colUnique);
		
		System.out.println("Reversed: " + colUnique.descendingSet());
		
		System.out.println("First: " + colUnique.first());
		System.out.println("Last: " + colUnique.last());
		
		System.out.println("Near to Black: " + colUnique.ceiling("Black"));
		
		
	}

}
