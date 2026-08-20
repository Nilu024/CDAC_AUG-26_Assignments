import java.util.Scanner;

public class AgeChecker{

	static void checkAgeCategory(int age){

		if(age > 55){
			System.out.println("You are Senior Citizen. Having Age - " + age);
		} else if(age > 18){
			System.out.println("You are Adult. Having Age - " + age);
		} else {
			System.out.println("You are Minor. Having Age - " + age);
		}
	
	}

	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		System.out.println("== Age Cheker ==");

		System.out.println();

		System.out.print("Enter Your Age: ");
		int age = sc.nextInt();
		checkAgeCategory(age);

	}
}