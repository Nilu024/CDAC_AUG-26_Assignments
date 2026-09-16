package StringLiterals;

public class indexOfCharInString {
	public static void main(String args[]) {
		String str = "The quick brown fox jumps over the lazy dog.";
		for (int i = 0; i < str.length(); i++) {
			System.out.print(str.charAt(i) + "-");
			System.out.print(str.codePointAt(i) + " ");		
		}
		
		System.out.println();

		        // Print alphabets
		        for (char ch = 'a'; ch <= 'z'; ch++) {
		            System.out.print(ch + " ");
		        }

		        System.out.println();

		        // Print separator
		        for (char ch = 'a'; ch <= 'z'; ch++) {
		            System.out.print("=");
		        }

		        System.out.println();

		        // Print index of each alphabet
		        for (char ch = 'a'; ch <= 'z'; ch++) {
		            System.out.print(str.indexOf(ch) + " ");
		}
	}
}
