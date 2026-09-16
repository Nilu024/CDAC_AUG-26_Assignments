package StringLiterals;

public class ReverseString {

    public static void main(String[] args) {

        String str = "The quick brown fox jumps";

        System.out.println("The given string is: " + str);

        StringBuilder sb = new StringBuilder(str);

        sb.reverse();

        System.out.println("The string in reverse order is:");
        System.out.println(sb);
    }
}
