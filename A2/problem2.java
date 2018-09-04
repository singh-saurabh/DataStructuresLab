import java.util.*;
import java.lang.*;
import java.io.*;
public class Problem
{
	static int[] mergeSortStacks(int[] A) {
        Stack<int[]> stack = new Stack<int[]>();
        Stack<int[]> stack2 = new Stack<int[]>();

        for (int i = 0; i < A.length; i++)
        {
            stack.push(new int[]{A[i]});
        }
        while (stack.size()>1)
        {
            while (stack.size()>1)
            {

                int[] r = stack.pop();
                int[] l = stack.pop();
                int[] merged=merge(l, r);
                stack2.push(merged);
            }
            while (stack2.size()>1)
            {

                int[] r = stack2.pop();
                int[] l = stack2.pop();
                int[] merged=merge(l, r);
                stack.push(merged);
            }
        }
        if (!stack.isEmpty() && !stack2.isEmpty()){
        	return merge(stack.pop(),stack2.pop());
        }
        return stack.isEmpty() ? stack2.pop() : stack.pop();


    }
  static  int[] merge(int L[], int R[])
{
    int i, j, k;
    int []arr=new int[L.length + R.length];
    i = 0;
    j = 0;
    k = 0;
    while (i < L.length && j < R.length)
    {
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < L.length)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < R.length)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    return arr;
}
	public static void main (String[] args) throws java.lang.Exception
	{
		int []a={2,3,0};
		for (int i=0;i<3;i++)
		System.out.print(a[i]+" ");
		a=mergeSortStacks(a);
		System.out.println();
		for (int i=0;i<3;i++)
		System.out.print(a[i]+" ");

	}
}
