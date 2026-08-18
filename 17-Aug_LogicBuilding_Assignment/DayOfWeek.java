import java.util.Scanner;

class DayOfWeek{

	public static String findDay(int dayNum){

		switch (dayNum){
		case 1 :
			return "Monday";
		case 2 :
			return "Tuesday";
		case 3 :
			return "WednesDay";
		case 4 :
			return "Thursday";
		case 5 :
			return "Friday";
		case 6 :
			return "Saturday";
		case 7 :
			return "Sunday";
		default:
			return "Invalid day Number";
		}
	}

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.println("Enter day number (1-7): ");
		int num = sc.nextInt();
		
		System.out.println(findDay(num));
		
		sc.close();
	}
}