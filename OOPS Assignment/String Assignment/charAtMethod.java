package StringLiterals;

public class charAtMethod {
	
	public static void main(String args[]) {
		String str = "Java Exercises!";
		
		byte indexes[] = {0, 10, 5};
		
		for(int i = 0; i < indexes.length; i++) {
			System.out.println("The character at position " + indexes[i] + " is " + str.charAt(indexes[i]));			
		}
	}

}
