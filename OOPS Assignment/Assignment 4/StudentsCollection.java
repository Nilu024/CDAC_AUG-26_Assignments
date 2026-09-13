
public class StudentsCollection {

	public static void main(String[] args) {
		Student stud = new Student();
		stud.display();
		Student stud1 = new Derived();
		stud1.display();
		Derived stud2 = new Derived();
		stud2.display();
		
		
	}

}
