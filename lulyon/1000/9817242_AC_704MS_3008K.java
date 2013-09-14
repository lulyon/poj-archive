import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		APlusB1000 obj = new APlusB1000();
		obj.main(args);
	}
}

class APlusB1000 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int a = scanner.nextInt();
		int b = scanner.nextInt();
		
		System.out.println(a + b);
	}
}
