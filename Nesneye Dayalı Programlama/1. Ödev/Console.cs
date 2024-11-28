using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NDP
{

    public class Nokta
    {
        int x, y;
        public Nokta()
        {
            x = 0;
            y = 0;
        }
        public Nokta(int X, int Y)
        {
            x = X;
            y = Y;
        }
        public int X { get => x; set => x = value; }
        public int Y { get => y; set => y = value; }
    }
    public class Nokta3d : Nokta
    {
        int z;
        public Nokta3d() : base() { z = 0; }
        public Nokta3d(int X, int Y, int Z)
        {
            z = Z;
        }
        public int Z { get => z; set => z = value; }
    }
    public class cember
    {
        Nokta m;
        int r;
        public cember()
        {
            m = new Nokta();
            r = 0;
        }
        public cember(Nokta M, int R)
        {
            m = M;
            r = R;
        }
        public int R { get => r; set => r = value; }
        public Nokta M { get => m; set => m = value; }
    }
    public class Duzlem
    {
        float a, b, c, d; // ax + by + cz + d = 0 düzlemin denklemi
        public Duzlem(float A, float B, float C, float D)
        {
            a = A;
            b = B;
            c = C;
            d = D;
        }
        public float A { get => a; set => a = value; }
        public float B { get => b; set => b = value; }
        public float C { get => c; set => c = value; }
        public float D { get => d; set => d = value; }
    }
    public static class Carpisma
    {
        public static bool CemberCarpisma(cember c1, cember c2)
        {
            float d = (float)Math.Sqrt(Math.Pow((c1.M.X - c2.M.X), 2) + Math.Pow((c1.M.Y - c2.M.Y), 2));
            if (d < c1.R + c2.R)
                return true;
            else
                return false;
        }
        public static bool KureCarpisma(kure k1, kure k2)
        {
            float d = (float)Math.Sqrt(Math.Pow((k1.M.X - k2.M.X), 2) + Math.Pow((k1.M.Y - k2.M.Y), 2) + Math.Pow((k1.M.Z - k2.M.Z), 2));
            if (d < k1.R + k2.R)
                return true;
            else
                return false;
        }

        public static bool DikdortgenCarpisma(dikdortgen d1, dikdortgen d2)
        {
                int Xa = d1.M.X + d1.En / 2;
                int Ya = d1.M.Y + d1.Boy / 2;
                int Xb = d2.M.X + d2.En / 2;
                int Yb = d2.M.Y + d2.Boy / 2;
                if (Math.Abs(Xa - Xb) < d1.En / 2 + d2.En / 2 && Math.Abs(Ya - Yb) < d1.Boy / 2 + d2.Boy / 2)
                    return true;
                else
                    return false;

            }
        public static bool SilindirCarpisma(silindir s1, silindir s2)
        {
            Nokta3d pa = new Nokta3d(s1.M.X, s1.M.Y + s1.H / 2, s1.M.Z);
            Nokta3d pb = new Nokta3d(s2.M.X, s2.M.Y + s2.H / 2, s2.M.Z);
            float d = (float)Math.Sqrt(Math.Pow((pa.X - pb.X), 2) + Math.Pow((pa.Y - pb.Y), 2) + Math.Pow((pa.Z - pb.Z), 2));
            if ((d < s1.R + s2.R) && Math.Abs(pb.Y - pa.Y) < (s1.H / 2 + s2.H / 2))
                return true;
            else
                return false;
        }
        public static bool NoktaDikdortgen(Nokta n1, dikdortgen d1)
        {
            float xMin = d1.M.X - d1.En / 2;
            float xMax = d1.M.X + d1.En / 2;
            float yMin = d1.M.Y - d1.Boy / 2;
            float yMax = d1.M.Y + d1.Boy / 2;

            // noktanın dikdörtgenin içinde olup olmadığını kontrol et
            if (n1.X >= xMin && n1.X <= xMax && n1.Y >= yMin && n1.Y <= yMax)
                return true; // çarpışma var
            else
                return false; // çarpışma yok
        }




        public static bool NoktaCember(Nokta n1, cember c1)
        {
            float dx = c1.M.X - n1.X;
            float dy = c1.M.Y - n1.Y;
            float distance = (float)Math.Sqrt(dx * dx + dy * dy);

            if (distance <= c1.R)
                return true; // çarpışma var
            else
                return false; // çarpışma yok
        }


        public static bool NoktaKure(Nokta3d n1,kure k1)
        {
            float d = (float)Math.Sqrt(Math.Pow((k1.M.X - n1.X), 2) + Math.Pow((k1.M.Y - n1.Y), 2) + Math.Pow((k1.M.Z - n1.Z), 2));
            if (d > k1.R)
                return true;
            else
                return false;
        }





        public static bool SilindirNokta(silindir s1, Nokta3d n1)
        {
            Nokta3d pa = new Nokta3d(s1.M.X, s1.M.Y + s1.H / 2, s1.M.Z);
            float d = (float)Math.Sqrt(Math.Pow((pa.X - n1.X), 2) + Math.Pow((pa.Y - n1.Y), 2) + Math.Pow((pa.Z - n1.Z), 2));

            if (d <= s1.R && n1.Y >= s1.M.Y && n1.Y <= s1.M.Y + s1.H)
                return true;
            else
                return false;
        }

        public static bool DikdortgenCember(dikdortgen d1, cember c1)
        {
            int Xa = d1.M.X + d1.En / 2;
            int Ya = d1.M.Y + d1.Boy / 2;
            float d = (float)Math.Sqrt(Math.Pow((Xa - c1.M.X), 2) + Math.Pow((Ya - c1.M.Y), 2));
            if (d < c1.R + d1.En / 2 && d < c1.R + d1.Boy / 2)
                return true;
            else
                return false;

        }
        public static bool KureSilindir(kure k1, silindir s1)
        {
            Nokta3d pa = new Nokta3d(s1.M.X, s1.M.Y + s1.H / 2, s1.M.Z);
            float d = (float)Math.Sqrt(Math.Pow((pa.X - k1.M.X), 2) + Math.Pow((pa.Y - k1.M.Y), 2) + Math.Pow((pa.Z - k1.M.Z), 2));
            if (d < k1.R + s1.R && d < k1.R + s1.H / 2)
                return true;
            else
                return false;
        }
        public static bool DikdortgenPrizmaCarpisma(DikdortgenPrizma p1, DikdortgenPrizma p2)
        {
            Nokta3d pa = new Nokta3d(p1.M.X, p1.M.Y + p1.Boy / 2, p1.M.Z);
            Nokta3d pb = new Nokta3d(p2.M.X, p2.M.Y + p2.Boy / 2, p2.M.Z);
            float d = (float)Math.Sqrt(Math.Pow((pa.X - pb.X), 2) + Math.Pow((pa.Y - pb.Y), 2) + Math.Pow((pa.Z - pb.Z), 2));
            if (d < p1.En / 2 + p2.En / 2 && Math.Abs(pb.Z - pa.Z) < p1.Yukseklik / 2 + p2.Yukseklik / 2)
                return true;
            else
                return false;
        }




        public static bool PrizmaNokta(DikdortgenPrizma p1, Nokta3d n1)
        {
            float minX = p1.M.X - p1.En / 2;
            float maxX = p1.M.X + p1.En / 2;
            float minY = p1.M.Y - p1.Boy / 2;
            float maxY = p1.M.Y + p1.Boy / 2;
            float minZ = p1.M.Z - p1.Yukseklik / 2;
            float maxZ = p1.M.Z + p1.Yukseklik / 2;

            if (n1.X >= minX && n1.X <= maxX &&
                n1.Y >= minY && n1.Y <= maxY &&
                n1.Z >= minZ && n1.Z <= maxZ)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static bool KureDikdortgenPrizma(kure k1, DikdortgenPrizma d1)
        {
            Nokta3d pa = new Nokta3d(d1.M.X, d1.M.Y + d1.Boy / 2, d1.M.Z);
            float d = (float)Math.Sqrt(Math.Pow((pa.X - k1.M.X), 2) + Math.Pow((pa.Y - k1.M.Y), 2) + Math.Pow((pa.Z - k1.M.Z), 2));
            if (d < k1.R + d1.En / 2 && d < k1.R + d1.Boy / 2 && d < k1.R + d1.Yukseklik / 2)
                return true;
            else
                return false;
        }
        public static bool KureDuzlemCarpisma(kure k, Duzlem p)
        {
            float distance = (k.M.X * p.A + k.M.Y * p.B + k.M.Z * p.C + p.D) / (float)Math.Sqrt(p.A * p.A + p.B * p.B + p.C * p.C);
            if (distance < k.R)
                return true;
            else
                return false;
        }

        public static bool DikdortgenPrizmaYuzeyCarpisma(DikdortgenPrizma prizma, Duzlem yuzey)
        {
            // Calculate the center of the prism
            int centerX = prizma.M.X + prizma.En / 2;
            int centerY = prizma.M.Y + prizma.Boy / 2;
            int centerZ = prizma.Yukseklik / 2;

            // Calculate the distance from the center of the prism to the plane
            float distance = (centerX * yuzey.A + centerY * yuzey.B + centerZ * yuzey.C + yuzey.D) / (float)Math.Sqrt(yuzey.A * yuzey.A + yuzey.B * yuzey.B + yuzey.C * yuzey.C);

            // Calculate the distance from the center of the prism to the closest point on the plane
            double closestDistance = Math.Abs(distance) - Math.Sqrt(Math.Pow(prizma.En / 2, 2) + Math.Pow(prizma.Boy / 2, 2) + Math.Pow(prizma.Yukseklik / 2, 2));

            if (closestDistance < 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        public static bool SilindirDuzlemCarpisma(silindir s, Duzlem p)
        {
            // find the distance between the center of the cylinder and the plane
            float distance = Math.Abs(p.A * s.M.X + p.B * s.M.Y + p.C * s.M.Z + p.D) / (float)Math.Sqrt(p.A * p.A + p.B * p.B + p.C * p.C);

            // if the distance is greater than the radius, there is no collision
            if (distance > s.R)
                return false;

            // project the center of the cylinder onto the plane to find the point of contact
            float projX = s.M.X - distance * p.A / (p.A * p.A + p.B * p.B + p.C * p.C);
            float projY = s.M.Y - distance * p.B / (p.A * p.A + p.B * p.B + p.C * p.C);
            float projZ = s.M.Z - distance * p.C / (p.A * p.A + p.B * p.B + p.C * p.C);

            // check if the point of contact is within the bounds of the cylinder
            float distX = projX - s.M.X;
            float distY = projY - s.M.Y;
            float distZ = projZ - s.M.Z;

            if (Math.Sqrt(distX * distX + distY * distY + distZ * distZ) <= s.H / 2)
                return true;
            else
                return false;
        }
    }
}

