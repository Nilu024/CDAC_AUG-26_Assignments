package StringLiterals;

public class comparatorString {
	
	public static void main(String args[]) {
		String str1 =  "This is Exercise 1";                                                                                  
		String str2 = "This is Exercise 2";     
		boolean bcomp = (str1 == str2) ;
		System.out.println("\"" + str1 + "\" is " + (bcomp ? "greater" : "less") + " than \"" + str2 + "\"");

	}
}
