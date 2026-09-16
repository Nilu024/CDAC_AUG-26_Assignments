package StringLiterals;

public class endsWith {
	public static void main(String args[]) {
		String str1 = "Python Exercises";
		String str2 = "Python Exercise";
		String endsAt = "se";
		
		System.out.println(str1 + "end with " + endsAt + "? " + (str1.endsWith(endsAt) ? " Yes" : " No"));
		System.out.println(str2 + "end with " + endsAt + "? " + (str2.endsWith(endsAt) ? "Yes" : " No"));
	}
}
