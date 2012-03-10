using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJR1A
{
    class Program
    {

        static void algo()
        {
        
        
        }
                
        
        static void Main(string[] args)
        {
            StreamReader input = new StreamReader("C:\\A-small.in");
            StreamWriter output = new StreamWriter("C:\\A-small.out");

            int cases;
            int no_of_dimensions;
            int[] v1= new int [802];
            int[] v2 = new int [802];
            //int no_of_searches;
            //string[] engines = new string[105];
            //string[] searches = new string[1005];
            int i;
            int answer = 0;
            int casecount = 1;
            int previndex, tempindex;
            string tempbuf;
            string buffer = input.ReadLine();
            cases = System.Convert.ToInt32(buffer);


            while (cases-- != 0)
            {
                answer = 0;
                //reading case inputs from file
                buffer = input.ReadLine();
                no_of_dimensions = System.Convert.ToInt32(buffer);

                previndex = 0;
                buffer = input.ReadLine();
                for (i = 0; i < no_of_dimensions; i++)
                {
                    
                    tempindex = buffer.IndexOf(' ');
                    if (tempindex == -1) v1[i] = System.Convert.ToInt32(buffer);
                    else
                    {
                        tempbuf = buffer.Substring(0, tempindex);
                        v1[i] = System.Convert.ToInt32(tempbuf);
                        buffer = buffer.Substring(tempindex+1);

                    }

                    
                }


                buffer = input.ReadLine();
                for (i = 0; i < no_of_dimensions; i++)
                {

                    tempindex = buffer.IndexOf(' ');
                    if (tempindex == -1) v2[i] = System.Convert.ToInt32(buffer);
                    else
                    {
                        tempbuf = buffer.Substring(0, tempindex);
                        v2[i] = System.Convert.ToInt32(tempbuf);
                        buffer = buffer.Substring(tempindex + 1);

                    }


                }

                //sort arrays
                int  j1, k1;
                for (j1 = 1; j1 < no_of_dimensions ; j1++)
                {
                    for ( k1 = 0; k1 < j1; k1++)
                    {
                        if (v1[j1] < v1[k1])
                        {
                            int temp = v1[k1];
                            v1[k1] = v1[j1];
                            v1[j1] = temp;
                        }
                    }
                }

                for (j1 = 1; j1 < no_of_dimensions; j1++)
                {
                    for ( k1 = 0; k1 < j1; k1++)
                    {
                        if (v2[j1] > v2[k1])
                        {
                            int temp = v2[k1];
                            v2[k1] = v2[j1];
                            v2[j1] = temp;
                        }
                    }
                }


                for (i = 0; i < no_of_dimensions; i++)
                {
                    answer += v1[i] * v2[i];
                }




                ////algo called here
                //if (no_of_searches <= 0 || no_of_engines <= 0) answer = 0;
                //else
                //    answer = algo(ref no_of_engines, ref engines, ref no_of_searches, ref searches);

                






                //writing solutions to file
                output.WriteLine("Case #{0}: {1}", casecount++, answer);


            }
            input.Close();
            output.Close();


        }
    }
}
