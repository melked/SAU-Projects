using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.IO;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;


namespace NDP
{
    public class kure :Form{
       

        Nokta3d m;
        int r;
        public kure()
        {
            m = new Nokta3d();
            r = 0;
        }
        public kure(Nokta3d M, int R)
        {
            m = M;
            r = R;
        }
        public Nokta3d M { get => m; set => m = value; }
        public int R { get => r; set => r = value; }
    }

   

}
