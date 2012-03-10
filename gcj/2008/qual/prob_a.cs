using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace GCJ_A
{
    class Program
    {

        private static int algo(ref int no_of_engines,ref string[] engines,ref int no_of_searches, ref string[] searches)
        {
            //iterate thru engines
            int maxdepth = -1;
            int engineselected;
            int start = 0;
            int changes = 0;

            while (start < no_of_searches)
            {
                maxdepth = -1;
                for (int i = 0; i < no_of_engines; i++)
                {
                    //searches for paths 
                    int count = start;
                    int depth = 0;
                    
                    while (engines[i] != searches[count] && count < no_of_searches)
                    {
                        depth++;
                        count++;
                    }
                    if (depth > maxdepth)
                    {
                        maxdepth = depth;
                        engineselected = i;
                    }

                }
                start = maxdepth+start;
                changes++;
            }

            return changes-1;
        }


        static void Main(string[] args)
        {
            StreamReader input=new StreamReader("C:\\A-large.in");
            StreamWriter output = new StreamWriter("C:\\A-large.out");
            
            int cases;
            int no_of_engines;
            int no_of_searches;
            string[] engines= new string [105];
            string[] searches= new string [1005];
            int i;
            int answer=0;
            int casecount=1;

            string buffer = input.ReadLine();
            cases = System.Convert.ToInt32(buffer);
            
            
            while (cases-- != 0)
            {
                //reading case inputs from file
                buffer = input.ReadLine();
                no_of_engines  = System.Convert.ToInt32(buffer);

                for (i = 0; i < no_of_engines; i++)
                {
                    buffer = input.ReadLine();
                    engines[i] = buffer;
                }


                buffer = input.ReadLine();
                no_of_searches = System.Convert.ToInt32(buffer);
                for (i = 0; i < no_of_searches; i++)
                {
                    buffer = input.ReadLine();
                    searches[i] = buffer;
                }


                //algo called here
                if (no_of_searches <= 0 || no_of_engines <= 0) answer = 0;
                else 
                answer = algo(ref no_of_engines,ref engines,ref no_of_searches,ref searches );


                //writing solutions to file
                output.WriteLine("Case #{0}: {1}", casecount++, answer);
                

            }
            input.Close();
            output.Close();
        }
    }
}
