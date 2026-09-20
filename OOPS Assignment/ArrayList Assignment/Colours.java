import java.util.ArrayList;

public class Colours {

	public static void main(String[] args) {
		
		ArrayList<String> color = new ArrayList<String>();
		
		color.add("Red");
		color.add("Blue");
		color.add("Yellow");
		color.add("Green");
		
		System.out.println(color);

		color.add(0, "Pink");
		System.out.println(color);
	
		System.out.println(color.get(2));
	
		color.set(2, "Black");
		System.out.println(color);
		
		color.remove(2);
		System.out.println(color);
				
		System.out.println(color.contains("Red") ? "Present" : "Not Present");

	}

}
