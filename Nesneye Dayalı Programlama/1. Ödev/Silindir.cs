using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDP
{
    

        public class silindir
        {
            Nokta3d m;
            int r;
            int h;
            public silindir()
            {
                m = new Nokta3d();

                r = 0;
                h = 0;
            }



            public silindir(Nokta3d M, int R, int H)
            {
                m = M;
                r = R;
                h = H;
            }
            public Nokta3d M { get => m; set => m = value; }
            public int R { get => r; set => r = value; }
            public int H { get => h; set => h = value; }

        }

    }

