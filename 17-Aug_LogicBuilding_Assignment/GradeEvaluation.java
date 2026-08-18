import java.util.Scanner;

class GradeEvaluation{
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter Marks of Maths Subject: ");
		int Maths = sc.nextInt();

		System.out.println("Enter Marks of Science Subject: ");
		int Science = sc.nextInt();

		System.out.println("Enter Marks of History Subject: ");
		int History = sc.nextInt();

		int Sum = Maths + Science + History;
		int Avg = Sum/3;

		System.out.println("Average marks " + Avg);

		if(Avg >= 90){
			System.out.println("Obtained Grade: A");
		}
		else if(Avg >= 70 && Avg < 90 ){
			System.out.println("Obtained Grade: B");
		}
		else if(Avg >= 50 && Avg < 70 ){
			System.out.println("Obtained Grade: C");
		}
		else if(Avg >= 30 && Avg < 50 ){
			System.out.println("Obtained Grade: D");
		}
		else if(Avg > 30){
			System.out.println("Failed..!");
		}


	}
}