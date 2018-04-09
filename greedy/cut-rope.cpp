//
// Created by YuXiao on 4/9/18.
//

// 动态规划or贪心算法--剪绳子/切割杆

//需求一：
//剪绳子，将长度为n的绳子剪成若干段，求各段长度乘积的最大值
//
//        分析：
//1、动态规划
//设f(n)代表长度为n的绳子剪成若干段的最大乘积，如果第一刀下去，第一段长度是i，那么剩下的就需要剪n-i，那么f(n)=max{f(i)f(n-i)}。而f(n)的最优解对应着f(i)和f(n-i)的最优解，假如f(i)不是最优解，那么其最优解和f(n-i)乘积肯定大于f(n)的最优解，和f(n)达到最优解矛盾，所以f(n)的最优解对应着f(i)和f(n-i)的最优解。首先，剪绳子是最优解问题，其次，大问题包含小问题，并且大问题的最优解包含着小问题的最优解，所以可以使用动态规划求解问题，并且从小到大求解，把小问题的最优解记录在数组中，求大问题最优解时就可以直接获取，避免重复计算。
//n<2时，由于每次至少减一次，所以返回0。n=2时，只能剪成两个1，那么返回1。n=3时，可以剪成3个1，或者1和2，那么最大乘积是2。当n>3时，就可以使用公式进行求解。
//f(4)=max{f(1)f(3), f(2)f(2)}
//f(5)=max{f(1)f(4), f(2)f(3)}
//...
//f(n)=max{f(1)f(n-1), f(2)f(n-2), f(3)f(n-3), ..., f(i)(fn-i), ...}
//因为需要保证f(i)f(n-i)不重复，就需要保证i<=n/2，这是一个限制条件，求1～n/2范围内的乘积，得到最大值
//2、贪心算法
//        n<2时，返回0；n=2时，返回1；n=3时，返回2
//        根据数学计算，当n>=5时，2(n-2)>n，3(n-3)>n，这就是说，将绳子剪成2和(n-2)或者剪成3和(n-3)时，乘积大于不剪的乘积，因此需要把绳子剪成2或者3。并且3(n-3)>=2(n-2)，也就是说，当n>=5时，应该剪尽量多的3，可以使最后的乘积最大。对于长度是n的绳子，我们可以剪出n/3个3，剩余长度是1或者2，如果余数是1，就可以把1和最后一个3合并成4，那么4剪出两个2得到的乘积是4，比1*3大，因此这种情况下，需要将3的个数减少1，变成两个2；如果余数是2，那么无需做修改。
//可以得到最大的乘积是：3^timesOf3 * 2^timesOf2
//        相比动态规划，计算更简便，但是需要一定的数学技巧。


//需求二：
//切割杆，现有长度为n的杆，已知1～n长度对应的价值数组是prices[n]，将其切割，求碎片的最大价值。
//
//分析：
//假设第一刀切下来是i，那么剩下的是n-i，假设f(n)代表切割n所能获得的最大价值，那么f(n)=max{f(i)+f(n-i)}，因此大问题可以分解成小问题，并且同剪绳子问题，大问题的最优解包括小问题的最优解，那么可以求出小问题的最优解，存到数组中，在求大问题最优解时就可以直接从数组中获取，最终获得最优解。
//f(0)=0
//f(1)=prices[0]
//f(2)=max{prices[1], f(1)+f(1)}
//f(3)=max{prices[2], f(1)+f(2)}
//f(4)=max{prices[3], f(1)+f(3), f(2)+f(2)}
//...
//f(n)=max{prices[n-1], f(1)+f(n-1), f(2)+f(n-2), ..., f(i)+f(n-i), ...}
//对于f(n)，为了保证f(i)+f(n-i)不重复，需要保证i<=n/2，这也是循环次数限制条件，在1～n/2范围内求解。


//import java.util.*;
//
//class Cut
//{
//    //剪绳子的动态规划算法
//public int cutRope1(int n){
//        //异常处理
//        if(n < 0)
//            throw new IllegalArgumentException("Illegal Paramters");
//
//        if(n < 2)
//            return 0;
//        if(n == 2)
//            return 1;
//        if(n == 3)
//            return 2;
//
//        //创建数组存储子问题最优解
//        int[] mul = new int[n+1];
//        mul[0]=0;
//        mul[1]=1;
//        mul[2]=2;
//        mul[3]=3;
//        for(int i = 4; i <= n; i++){
//            int max = 0;
//            for(int j = 1; j <= i/2; j++){
//                int temp = mul[j]*mul[i-j];
//                if(max < temp)
//                    max = temp;
//            }
//
//            mul[i] = max;
//        }
//
//        return mul[n];
//    }
//
//    //如果允许不剪操作，那么受影响的只是n=1，n=2，n=3
//public int cutRope2(int n){
//        if(n < 0)
//            throw new IllegalArgumentException("Illegal Paramters");
//
//        if(n == 0)
//            return 0;
//        if(n == 1)
//            return 1;
//
//        int[] mul = new int[n+1];
//        mul[0]=0;
//        mul[1]=1;
//        for(int i = 2; i <= n; i++){
//            int max = i;
//
//            for(int j = 1; j <= i/2; j++){
//                int temp = mul[j]*mul[i-j];
//
//                if(max < temp)
//                    max = temp;
//            }
//
//            mul[i] = max;
//        }
//
//        return mul[n];
//    }
//
//    //贪心算法
//public int cutRope3(int n){
//        //异常处理
//        if(n < 0)
//            throw new IllegalArgumentException("Illegal Paramters");
//
//        if(n < 2)
//            return 0;
//        if(n == 2)
//            return 1;
//        if(n == 3)
//            return 2;
//
//        int timesOf3 = n/3;
//
//        //如果剩余1，那么将1和一个3组成4可得到最大乘积
//        if(n - timesOf3*3 == 1)
//            timesOf3 -= 1;
//
//        int timesOf2 = (n - timesOf3*3) / 2;
//
//        return (int)Math.pow(3, timesOf3)*(int)Math.pow(2, timesOf2);
//    }
//
//    //切割杆
//public int maxValue(int[] prices, int n){
//        //异常处理
//        if(prices == null || prices.length != n)
//            throw new IllegalArgumentException("Illegal Paramters");
//
//        if(prices.length == 0)
//            return 0;
//
//        //存储小问题的最优解
//        int[] value = new int[n+1];
//
//        for(int i = 1; i <= n; i++){
//            int max = prices[i-1];
//
//            for(int j = 1; j <= i/2; j++){
//                int temp = value[j]+value[i-j];
//
//                if(max < temp)
//                    max = temp;
//            }
//
//            value[i] = max;
//        }
//
//        return value[n];
//    }
//}
//
//class CutDemo{
//public static void main(String[] args){
//        Scanner scan = new Scanner(System.in);
//        Cut cut = new Cut();
//
//        //测试剪绳子
//        System.out.println("请输入绳子的长度：");
//        int len = scan.nextInt();
//        System.out.println("长度"+len+"绳子剪成若干段（至少两段）后的乘积最大值："+cut.cutRope1(len));
//        System.out.println("长度"+len+"绳子剪成若干段（可以不剪）后的乘积最大值："+cut.cutRope2(len));
//        System.out.println("长度"+len+"绳子剪成若干段（至少两段）后的乘积最大值："+cut.cutRope3(len));
//
//        //测试切割杆
//        System.out.println("请输入杆的长度：");
//        int n = scan.nextInt();
//
//        int[] prices = new int[n];
//        for(int i = 0; i < n; i++)
//        {
//            System.out.print("prices["+i+"] = ");
//            prices[i] = scan.nextInt();
//        }
//
//        System.out.println("杆切割之后的最大价值为："+cut.maxValue(prices, n));
//    }
//}