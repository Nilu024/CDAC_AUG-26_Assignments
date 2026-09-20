import java.util.ArrayList;

public class LangPerform {

	public static void main(String[] args) {
		
		ArrayList<String> lang = new  ArrayList<String>();
		
		lang.add("Java");
		lang.add("Python");
		lang.add("C++");
		lang.add("JavaScript");
		
		lang.add(0, "C");
		
		lang.set(2, "C#");
		
		lang.remove(4);
		
		System.out.println(lang.contains("C++") ? "Exists" : "Does Not Exist");
		System.out.println(lang.contains("Python") ? "Exists" : "Does Not Exist");
		
		System.out.println(lang);
	}

}
