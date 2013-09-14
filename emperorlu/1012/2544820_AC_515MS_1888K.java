import java.io.*;
public class Main{
	static int[] a=new int[14];
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int k=1;
		while (k<14) {
			int times = 0;
			he:while (true) {
				out: for (int p = k; p < 2 * k; p++) {
					int i = times * 2 * k + p + 1;					
						int t = 1;
						for (int j = 2 * k; j > k;) {
							t = (t + i - 1) % j;
							if (t == 0 || t > k) {
								j--;
								if (t == 0)
									t = 1;
								else
									t = t % j;
							} else
								continue out;
						}
						a[k-1]=i;
						break he;
					}
				times++;
				}
			k++;
			}
		
		while(true){
			int m = Integer.parseInt(in.readLine().trim());
			if (m == 0)
				return;
			System.out.println(a[m-1]);
		}
		}
	}
