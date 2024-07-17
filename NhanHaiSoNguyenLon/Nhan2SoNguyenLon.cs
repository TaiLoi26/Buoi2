using System;
using System.Text;

public class NhanHaiSoNguyenLon
{
    public static string PhepNhan(string num1, string num2)
    {
        int len1 = num1.Length;
        int len2 = num2.Length;
        int[] result = new int[len1 + len2];

        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        StringBuilder sb = new StringBuilder();
        foreach (int num in result)
        {
            if (!(sb.Length == 0 && num == 0))
            {
                sb.Append(num);
            }
        }

        return sb.Length == 0 ? "0" : sb.ToString();
    }

    public static void Main(string[] args)
    {
        string num1 = "123456789";
        string num2 = "987654321";

        string result = PhepNhan(num1, num2);
        Console.WriteLine("Tich cua hai so nguyen lon la: " + result);

        Console.ReadLine();
    }
}
