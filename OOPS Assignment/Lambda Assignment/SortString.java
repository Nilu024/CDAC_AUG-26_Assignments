import java.util.Comparator;

public class SortString {

	public static void main(String[] args) {
		
		String[] names = {"Rahul", "Amit", "Sneha", "Vikas", "Priya"};
		
		Arrays.sort(names, (a, b) -> a.compareTo(b));

		for (String n : names) {
			System.out.print(n + ", ");
		}
	}

}
