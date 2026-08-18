import java.util.Scanner;

class LeapYear{
	
	public static boolean IsLeap(int year) {

		if (year % 400 == 0)
            		return true;

        	if (year % 100 == 0)
	            return false;

        	if (year % 4 == 0)
	            return true;

        	return false;
    	}

	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		System.out.println("Enter Year: ");
		int year = sc.nextInt();

        	System.out.println(IsLeap(year) ? "It is a Leap Year" : "Not a Leap Year");	
	}
}