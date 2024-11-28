using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace NDP
{


    public class dikdortgen 
    {
        
        Nokta m;
        int en;
        int boy;
        public dikdortgen()
        {
            m = new Nokta();
            en = 0;
            boy = 0;
        }
        public dikdortgen(Nokta M, int En, int Boy)
        {
            m = M;
            en = En;
            boy = Boy;
        }
        public Nokta M { get => m; set => m = value; }

        public int En { get => en; set => en = value; }
        public int Boy { get => boy; set => boy = value; }
        public void Draw(Graphics g)
        {
            // Çizimlerin rengini ve kalınlığını ayarlayın
            Pen pen = new Pen(Color.Black, 2);

            // Dikdörtgeni çizdirme
            g.DrawRectangle(pen, M.X - En / 2, M.Y - Boy / 2, En, Boy);
        }

    }
}  

