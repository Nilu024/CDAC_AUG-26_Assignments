import java.util.Scanner;

public class CountVowelsString{

	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter a word: ");
		String name = sc.nextLine();	
		int count = 0;

		name = name.toLowerCase();

		for(int i = 0; i < name.length(); i++){
			char letter = name.charAt(i);
			if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){ count++; }
		}
		System.out.println(count);
	}
}