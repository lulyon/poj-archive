import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		BS2249 obj = new BS2249();
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

class BS2249 {
	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		while (scanner.hasNext()) {
			int n = scanner.nextInt();
			int m = scanner.nextInt();

			if(n - m < m) m = n - m;
			if (n == 0 && m == 0)
				break;
			if (m == 0) {
				System.out.println("1");
				continue;
			}

			double rs = 1.0d;
			int i, j;
			for (i = 1, j = n - m + 1; i <= m && j <= n;) {
				if (rs >= 1.0) {
					rs = rs / i;
					++i;
				} else {
					rs = rs * j;
					++j;
				}
			}

			while (i <= m) {
				rs = rs / i;
				++i;
			}

			while (j <= n) {
				rs = rs * j;
				++j;
			}
			System.out.println((int) rs);
		}
	}
}
