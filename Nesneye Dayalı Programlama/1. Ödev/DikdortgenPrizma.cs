using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDP
{
    public class DikdortgenPrizma
    {
        Nokta3d m;
        int en;
        int boy;
        int yukseklik;

        public DikdortgenPrizma()
        {
            m = new Nokta3d();
            en = 0;
            boy = 0;
            yukseklik = 0;
        }

        public DikdortgenPrizma(Nokta3d M, int En, int Boy, int Yukseklik)
        {
            m = M;
            en = En;
            boy = Boy;
            yukseklik = Yukseklik;
        }

        public Nokta3d M { get => m; set => m = value; }
        public int En { get => en; set => en = value; }
        public int Boy { get => boy; set => boy = value; }
        public int Yukseklik { get => yukseklik; set => yukseklik = value; }

        public int Hacim()
        {
            return en * boy * yukseklik;
        }
    }
}
