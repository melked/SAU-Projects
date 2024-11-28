/****************************************************************************
**                        SAKARYA ÜNİVERSİTESİ BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
                         BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ PROGRAMLAMAYA GİRİŞİ DERSİ
**                                        PROJE ÖDEVİ
**
**                        ÖĞRENCİ ADI : MELİKE DEMİRTAŞ
**                        ÖĞRENCİ NUMARASI : G211210003
**                        DERS GRUBU : 2C
**                        YOUTUBE LİNKİ: https://youtu.be/Vk5T3U8kMWg
**
**
**
**

****************************************************************************/

using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
namespace NDP
{

    class AnaPencere : Form
    {
        public Button DikdortgenNokta1;
        public Button NoktaCember1;
        public Button DikdortgenCarpisma1;
        public Button CemberCarpisma1;
        public Button KureCarpisma1;
        public Button SilindirCarpisma1;
        public Button NoktaKure1;
        public Button SilindirNokta1;
        public Button DikdortgenCember1;
        public Button KureSilindir1;
        public Button PrizmaCarpisma1;
        public Button KureDikdortgenPrizma1;
        public Button PrizmaNokta1;

        public AnaPencere(int width, int height)
        {
            Width = width;
            Height = height;

            Paint += AnaPencere_Paint1;
            Paint += AnaPencere_Paint2;
            Paint += AnaPencere_Paint3;
            Paint += AnaPencere_Paint4;
            Paint += AnaPencere_Paint5;
            Paint += AnaPencere_Paint6;
            Paint += AnaPencere_Paint7;
            Paint += AnaPencere_Paint8;
            Paint += AnaPencere_Paint9;
            Paint += AnaPencere_Paint10;
            Paint += AnaPencere_Paint11;
            Paint += AnaPencere_Paint12;
            Paint += AnaPencerem_Paint13;

            DikdortgenNokta1 = new Button();
            Controls.Add(DikdortgenNokta1);
            DikdortgenNokta1.Text = "D&N";
            DikdortgenNokta1.SetBounds(0, 50, 150, 50);
            DikdortgenNokta1.Click += Button_Click13;

            NoktaCember1 = new Button();
            Controls.Add(NoktaCember1);
            NoktaCember1.Text = "N&C";
            NoktaCember1.SetBounds(0, 100, 150, 50);
            NoktaCember1.Click += Button_Click1;

            CemberCarpisma1 = new Button();
            Controls.Add(CemberCarpisma1);
            CemberCarpisma1.Text = "C&C";
            CemberCarpisma1.SetBounds(0, 150, 150, 50);
            CemberCarpisma1.Click += Button_Click2;

            DikdortgenCarpisma1 = new Button();
            Controls.Add(DikdortgenCarpisma1);
            DikdortgenCarpisma1.Text = "D&D";
            DikdortgenCarpisma1.SetBounds(0, 200, 150, 50);
            DikdortgenCarpisma1.Click += Button_Click3;

            KureCarpisma1 = new Button();
            Controls.Add(KureCarpisma1);
            KureCarpisma1.Text = "K&K";
            KureCarpisma1.SetBounds(0, 250, 150, 50);
            KureCarpisma1.Click += Button_Click4;


            SilindirCarpisma1 = new Button();
            Controls.Add(SilindirCarpisma1);
            SilindirCarpisma1.Text = "S&S";
            SilindirCarpisma1.SetBounds(0, 300, 150, 50);
            SilindirCarpisma1.Click += Button_Click5;

            NoktaKure1 = new Button();
            Controls.Add(NoktaKure1);
            NoktaKure1.Text = "N&K";
            NoktaKure1.SetBounds(0, 350, 150, 50);
            NoktaKure1.Click += Button_Click6;

            SilindirNokta1 = new Button();
            Controls.Add(SilindirNokta1);
            SilindirNokta1.Text = "S&N";
            SilindirNokta1.SetBounds(0, 400, 150, 50);
            SilindirNokta1.Click += Button_Click7;

            DikdortgenCember1 = new Button();
            Controls.Add(DikdortgenCember1);
            DikdortgenCember1.Text = "D&C";
            DikdortgenCember1.SetBounds(0, 450, 150, 50);
            DikdortgenCember1.Click += Button_Click8;

            KureSilindir1 = new Button();
            Controls.Add(KureSilindir1);
            KureSilindir1.Text = "S&K";
            KureSilindir1.SetBounds(0, 500, 150, 50);
            KureSilindir1.Click += Button_Click9;

            PrizmaCarpisma1 = new Button();
            Controls.Add(PrizmaCarpisma1);
            PrizmaCarpisma1.Text = "DP&DP";
            PrizmaCarpisma1.SetBounds(0, 550, 150, 50);
            PrizmaCarpisma1.Click += Button_Click10;

            KureDikdortgenPrizma1 = new Button();
            Controls.Add(KureDikdortgenPrizma1);
            KureDikdortgenPrizma1.Text = "K&DP";
            KureDikdortgenPrizma1.SetBounds(0, 600, 150, 50);
            KureDikdortgenPrizma1.Click += Button_Click11;

            PrizmaNokta1 = new Button();
            Controls.Add(PrizmaNokta1);
            PrizmaNokta1.Text = "N&DP";
            PrizmaNokta1.SetBounds(0, 650, 150, 50);
            PrizmaNokta1.Click += Button_Click12;
        }
        private void AnaPencere_Paint9(object? sender, PaintEventArgs e)
        {
            NoktaCiz(e.Graphics, 200, 100, 10, Color.Blue);
            PrizmaCiz(e.Graphics, 300, 200, 100, 80, 70);
        }
        private void Button_Click12(object? sender, EventArgs e)
        {
            Nokta3d n1 = new Nokta3d(400, 100, 40);
            Nokta3d n2 = new Nokta3d(300, 200, 500);
            DikdortgenPrizma prizma1 = new DikdortgenPrizma(n2, 50, 80, 40);

            if (Carpisma.PrizmaNokta(prizma1, n1))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        private void AnaPencere_Paint10(object? sender, PaintEventArgs e)
        {
            KureCiz(e.Graphics, 600,200, 50);
            PrizmaCiz(e.Graphics, 600, 200, 190, 150, 100);
        }

        private void Button_Click11(object? sender, EventArgs e)
        {

            Nokta3d n1 = new Nokta3d(600, 200, 300);
            Nokta3d n2 = new Nokta3d(600, 200, 300);
            kure k1 = new kure(n1, 50);
            DikdortgenPrizma Prizma1 = new DikdortgenPrizma(n2, 120, 100, 150);

            if (Carpisma.KureDikdortgenPrizma(k1, Prizma1))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        private void AnaPencere_Paint8(object? sender, PaintEventArgs e)
        {
            PrizmaCiz(e.Graphics, 350, 500, 60, 100, 180);
            PrizmaCiz(e.Graphics, 300, 400, 80, 100,140);
        }
        private void Button_Click10(object? sender, EventArgs e)
        {
            Nokta3d n1 = new Nokta3d(350, 500, 200);
            Nokta3d n2 = new Nokta3d(300, 400, 600);
            DikdortgenPrizma prizma1 = new DikdortgenPrizma(n1, 120, 100, 180);
            DikdortgenPrizma prizma2 = new DikdortgenPrizma(n2,80, 100, 140);

            if (Carpisma.DikdortgenPrizmaCarpisma(prizma1, prizma2))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }


        }

        private void AnaPencere_Paint7(object? sender, PaintEventArgs e)
        {
            SilindirCiz(e.Graphics, 700, 600, 50, 100);
            KureCiz(e.Graphics, 710, 600, 50);
        }
        private void Button_Click9(object? sender, EventArgs e)
        {
            Nokta3d n1 = new Nokta3d(550, 600, 300);
            Nokta3d n2 = new Nokta3d(700, 600, 290);
            kure Kure1 = new kure(n1, 50);
            silindir silindir1 = new silindir(n2, 50, 100);

            if (Carpisma.KureSilindir(Kure1, silindir1))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }

        }
        private void AnaPencere_Paint3(object? sender, PaintEventArgs e)
        {
            Graphics dikdortgen = e.Graphics;
            Graphics cember = e.Graphics;

            dikdortgen.DrawRectangle(Pens.Blue,900, 300, 20, 100);
            cember.DrawEllipse(Pens.Blue, 850, 300, 40, 80);

        }

        private void Button_Click8(object? sender, EventArgs e)
        {
            Nokta n1 = new Nokta(900, 300);
            Nokta n2 = new Nokta(850, 300);
            dikdortgen dikdortgen1 = new dikdortgen(n1, 20, 100);
            cember cember1 = new cember(n2, 40);

            using (Graphics graphics = this.CreateGraphics())
            {

                if (Carpisma.DikdortgenCember(dikdortgen1, cember1))
                {
                    MessageBox.Show("Çarpışma var!");
                }
                else
                {
                    MessageBox.Show("Çarpışma yok!");
                }
            }
        }



        private void AnaPencere_Paint11(object? sender, PaintEventArgs e)
        {
            NoktaCiz(e.Graphics, 1000, 650, 10, Color.Blue);
            SilindirCiz(e.Graphics, 900, 500, 250, 300);
        }
        private void Button_Click7(object? sender, EventArgs e)
        {
            Nokta3d n1 = new Nokta3d(900, 400, 200);
            Nokta3d n2 = new Nokta3d(1000, 650, 200);

            silindir silindir1 = new silindir(n1, 250, 300);

            if (Carpisma.SilindirNokta(silindir1, n2))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        private void AnaPencere_Paint12(object? sender, PaintEventArgs e)
        {
            NoktaCiz(e.Graphics, 1300, 400, 10, Color.Blue);
            KureCiz(e.Graphics, 1300, 300, 90);
        }
        private void Button_Click6(object? sender, EventArgs e)
        {
            Nokta3d n2 = new Nokta3d(1300, 400, 100);
            Nokta3d n1 = new Nokta3d(1300, 300, 50);
            kure k1 = new kure(n1, 90);
            if (Carpisma.NoktaKure(n1, k1))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        private void AnaPencerem_Paint13(object? sender, PaintEventArgs e)
        {
            SilindirCiz(e.Graphics, 1300, 600, 250, 200);
            SilindirCiz(e.Graphics, 1200, 750, 250, 200);
        }

        private void Button_Click5(object? sender, EventArgs e)
        {
            Nokta3d n1 = new Nokta3d(1300, 600, 100);
            Nokta3d n2 = new Nokta3d(1200, 750, 100);
            silindir Silindir1 = new silindir(n1, 25, 200);
            silindir Silindir2 = new silindir(n2, 25, 200);
            if (Carpisma.SilindirCarpisma(Silindir1, Silindir2))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        private void AnaPencere_Paint6(object? sender, PaintEventArgs e)
        {
            KureCiz(e.Graphics, 1400, 600, 50);
            KureCiz(e.Graphics, 1500, 500, 100);

        }


        private void Button_Click4(object? sender, EventArgs e)
        {
            Nokta3d n1 = new Nokta3d(1400, 600, 100);
            Nokta3d n2 = new Nokta3d(1500, 500, 100);
            kure kure1 = new kure(n1, 50);
            kure kure2 = new kure(n2, 100);
            if (Carpisma.KureCarpisma(kure1, kure2))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        private void Button_Click2(object? sender, EventArgs e)
        {


            Nokta n1 = new Nokta(800, 800);
            Nokta n2 = new Nokta(700, 700);
            cember Cember1 = new cember(n1, 50);
            cember Cember2 = new cember(n2, 80);

            // İki çemberin çarpışmasını kontrol et
            bool carpismaVar = Carpisma.CemberCarpisma(Cember1, Cember2);

            // Çarpışma durumuna göre mesaj kutusu göster
            if (carpismaVar)
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }

        }
        private void AnaPencere_Paint2(object? sender, PaintEventArgs e)
        {
            Graphics graphics = e.Graphics;
            graphics.DrawEllipse(Pens.Blue, 800, 700, 50, 100);
            graphics.DrawEllipse(Pens.Blue, 700, 700, 80, 160);
        }





        //Dikdörtgen Dikdörtgen

        private void AnaPencere_Paint1(object? sender, PaintEventArgs e)
        {
            Graphics dikdortgen = e.Graphics;
            dikdortgen.DrawRectangle(Pens.Blue, 900, 300, 200, 200);
            dikdortgen.DrawRectangle(Pens.Blue, 800, 250, 200, 200);
        }
        private void Button_Click3(object? sender, EventArgs e)
        {
            Nokta n1 = new Nokta(900, 300);
            Nokta n2 = new Nokta(800, 250);
            dikdortgen Dikdortgen1 = new dikdortgen(n1, 200, 200);
            dikdortgen Dikdortgen2 = new dikdortgen(n2, 200, 200);



            if (Carpisma.DikdortgenCarpisma(Dikdortgen1, Dikdortgen2))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }



        private void AnaPencere_Paint4(object? sender, PaintEventArgs e)
        {
            Graphics cember = e.Graphics;
            cember.DrawEllipse(Pens.Blue, 1600, 500, 40, 80);
            NoktaCiz(e.Graphics, 1600, 400, 15, Color.Blue);
        }

        private void Button_Click1(object? sender, EventArgs e)
        {
            Nokta n = new Nokta(1600, 500);
            Nokta nokta1 = new Nokta(1600, 400);
            cember cember1 = new cember(n, 20);
            if (Carpisma.NoktaCember(nokta1, cember1))
            {
                MessageBox.Show("Çarpışma Var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");

            }
        }
        private void AnaPencere_Paint5(object? sender, PaintEventArgs e)
        {
            NoktaCiz(e.Graphics, 1550, 800, 10, Color.Blue);
            Graphics dikdortgen = e.Graphics;
            dikdortgen.DrawRectangle(Pens.Blue, 1500, 750, 500, 500);

        }
        private void Button_Click13(object? sender, EventArgs e)
        {
            Nokta n = new Nokta(1500, 750);
            Nokta nokta1 = new Nokta(1550,800);
            dikdortgen dikdortgen1 = new dikdortgen(n, 1500, 1300);

            if (Carpisma.NoktaDikdortgen(nokta1, dikdortgen1))
            {
                MessageBox.Show("Çarpışma var!");
            }
            else
            {
                MessageBox.Show("Çarpışma yok!");
            }
        }
        public void KureCiz(Graphics graphics, int MerkezX, int MerkezY, int radius)
        {
            Brush brush = new SolidBrush(Color.Blue);

            // Küreyi dolu olarak çiz
            graphics.FillEllipse(brush, MerkezX - radius, MerkezY - radius, radius * 2, radius * 2);

            // Kürenin merkezini ve yarıçapını göster
            Font font = new Font("Arial", 10);
            string radiusText = "Radius: " + radius.ToString();
            string centerText = "Center: (" + MerkezX.ToString() + ", " + MerkezY.ToString() + ")";
            graphics.DrawString(radiusText, font, Brushes.Black, MerkezX - radius, MerkezY - radius - 20);
            graphics.DrawString(centerText, font, Brushes.Black, MerkezX - radius, MerkezY + radius + 10);
        }

        private void DrawCircle(Graphics g, Pen pen, int MerkezX, int MerkezY, int radius)
        {
            g.DrawEllipse(pen, MerkezX - radius, MerkezY - radius, 2 * radius, 2 * radius);
        }
        private void DrawLine(Graphics g, Pen pen, int x1, int y1, int x2, int y2)
        {
            g.DrawLine(pen, x1, y1, x2, y2);
        }

        private void PrizmaCiz(Graphics g, int MerkezX, int MerkezY, int width, int height, int depth)
        {
            int topY = MerkezY - height / 2;
            int bottomY = MerkezY + height / 2;

            DrawLine(g, Pens.Black, MerkezX - width / 2, topY, MerkezX + width / 2, topY);
            DrawLine(g, Pens.Black, MerkezX - width / 2, bottomY, MerkezX + width / 2, bottomY);
            DrawLine(g, Pens.Black, MerkezX - width / 2, topY, MerkezX - width / 2, bottomY);
            DrawLine(g, Pens.Black, MerkezX + width / 2, topY, MerkezX + width / 2, bottomY);
            DrawLine(g, Pens.Black, MerkezX - width / 2, topY, MerkezX - width / 2 - depth / 2, topY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX + width / 2, topY, MerkezX + width / 2 - depth / 2, topY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX - width / 2, bottomY, MerkezX - width / 2 - depth / 2, bottomY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX + width / 2, bottomY, MerkezX + width / 2 - depth / 2, bottomY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX - width / 2 - depth / 2, topY + depth / 2, MerkezX + width / 2 - depth / 2, topY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX - width / 2 - depth / 2, topY + depth / 2, MerkezX - width / 2 - depth / 2, bottomY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX + width / 2 - depth / 2, topY + depth / 2, MerkezX + width / 2 - depth / 2, bottomY + depth / 2);
            DrawLine(g, Pens.Black, MerkezX - width / 2 - depth / 2, bottomY + depth / 2, MerkezX + width / 2 - depth / 2, bottomY + depth / 2);
        }
        void SilindirCiz(Graphics g, int x, int y, int width, int height)
        {  // Üst yüzeyin çizimi
            g.DrawEllipse(Pens.Black, x, y, width, height / 2);

            // Alt yüzeyin çizimi
            g.DrawEllipse(Pens.Black, x, y + height / 2, width, height / 2);

            // Yan yüzeyleri çizimi
            int yaricap = width / 2; // Yan yüzeylerin çizimi için yarıçap hesaplanır

            // Üst ve alt yüzeyleri düz çizgi ile bağlama
            g.DrawLine(Pens.Black, x, y + height / 4, x, y + 3 * height / 4);
            g.DrawLine(Pens.Black, x + width, y + height / 4, x + width, y + 3 * height / 4);

        }

        private void InitializeComponent()
        {

        }

        private void NoktaCiz(Graphics graphics, int x, int y, int size, Color color)
        {
            using (Brush brush = new SolidBrush(color))
            {
                int xOrta = x - size / 2;
                int yOrta = y - size / 2;
                graphics.FillEllipse(brush, xOrta, yOrta, size, size);
            }
        }
    }
}





