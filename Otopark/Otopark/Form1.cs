using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
using System.IO;


namespace Otopark
{
    public partial class form1 : Form
    {
        public form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
           
           

        }

        private void form1_Load(object sender, EventArgs e)
        {
            pictureBox1.Visible = false;
            pictureBox2.Visible = false;
            pictureBox3.Visible = false;
            pictureBox4.Visible = false;
            pictureBox5.Visible = false;
            pictureBox6.Visible = false;
            pictureBox7.Visible = false;
            pictureBox8.Visible = false;
            pictureBox9.Visible = false;
            pictureBox10.Visible = false;

            timer1.Interval = 1000;
            System.Windows.Forms.Form.CheckForIllegalCrossThreadCalls = false;

            foreach (string ComPorts in SerialPort.GetPortNames())


                comboBox1.Items.Add(ComPorts);

            if (comboBox1.Items.Count > 0)
            {
                comboBox1.Text = comboBox1.Items[0].ToString();


            }
        }

        private void form1_Closing(object sender, EventArgs e)
        {
            if (serialPort1.IsOpen) serialPort1.Close();

        }
        String portnamex = "";
        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.PortName = comboBox1.SelectedItem.ToString();
            serialPort1.Open();
            portnamex=comboBox1.SelectedItem.ToString();
            MessageBox.Show(portnamex + " Portu seçildi");
            timer1.Start();
        }
        
        char[] charArr = new char[10];
        char[] oldOne = new char[10];
        int passed = 0;
        private void timer1_Tick(object sender, EventArgs e)
        {
            string a = serialPort1.ReadExisting();
            Thread.Sleep(500);
            charArr = a.ToCharArray();
            if (a.Length > 2)
            {
                
                  
                if (charArr[0] == '1')
                {
                    pictureBox5.Visible = true;

                }
                else
                {
                    pictureBox5.Visible = false;
                }
                if (charArr[1] == '1')
                {
                    pictureBox4.Visible = true;
                }
                else
                {
                    pictureBox4.Visible = false;
                }
                if (charArr[2] == '1')
                {
                    pictureBox3.Visible = true;
                }
                else
                {
                    pictureBox3.Visible = false;
                }
                if (charArr[3] == '1')
                {
                    pictureBox2.Visible = true;
                }
                else
                {
                    pictureBox2.Visible = false;
                }
                if (charArr[4] == '1')
                {
                    pictureBox1.Visible = true;
                }
                else
                {
                    pictureBox1.Visible = false;
                }
                if (charArr[5] == '1')
                {
                    pictureBox6.Visible = true;
                }
                else
                {
                    pictureBox6.Visible = false;
                }
                if (charArr[6] == '1')
                {
                    pictureBox7.Visible = true;
                }
                else
                {
                    pictureBox7.Visible = false;
                }
                if (charArr[7] == '1')
                {
                    pictureBox8.Visible = true;
                }
                else
                {
                    pictureBox8.Visible = false;
                }
                if (charArr[8] == '1')
                {
                    pictureBox9.Visible = true;
                }
                else
                {
                    pictureBox9.Visible = false;
                }
                if (charArr[9] == '1')
                {
                    pictureBox10.Visible = true;
                }
                else
                {
                    pictureBox10.Visible = false;
                }
                oldOne = charArr;
                passed = 1;
            }
            else if (a.Length < 2 && passed == 1)
            {

                if (oldOne[0] == '1')
                {
                    pictureBox5.Visible = true;

                }
                else
                {
                    pictureBox5.Visible = false;
                }
                if (oldOne[1] == '1')
                {
                    pictureBox4.Visible = true;
                }
                else
                {
                    pictureBox4.Visible = false;
                }
                if (oldOne[2] == '1')
                {
                    pictureBox3.Visible = true;
                }
                else
                {
                    pictureBox3.Visible = false;
                }
                if (oldOne[3] == '1')
                {
                    pictureBox2.Visible = true;
                }
                else
                {
                    pictureBox2.Visible = false;
                }
                if (oldOne[4] == '1')
                {
                    pictureBox1.Visible = true;
                }
                else
                {
                    pictureBox1.Visible = false;
                }
                if (oldOne[5] == '1')
                {
                    pictureBox6.Visible = true;
                }
                else
                {
                    pictureBox6.Visible = false;
                }
                if (oldOne[6] == '1')
                {
                    pictureBox7.Visible = true;
                }
                else
                {
                    pictureBox7.Visible = false;
                }
                if (oldOne[7] == '1')
                {
                    pictureBox8.Visible = true;
                }
                else
                {
                    pictureBox8.Visible = false;
                }
                if (oldOne[8] == '1')
                {
                    pictureBox9.Visible = true;
                }
                else
                {
                    pictureBox9.Visible = false;
                }
                if (oldOne[9] == '1')
                {
                    pictureBox10.Visible = true;
                }
                else
                {
                    pictureBox10.Visible = false;
                }

            }
            else
            {
                pictureBox1.Visible = false;
                pictureBox2.Visible = false;
                pictureBox3.Visible = false;
                pictureBox4.Visible = false;
                pictureBox5.Visible = false;
                pictureBox6.Visible = false;
                pictureBox7.Visible = false;
                pictureBox8.Visible = false;
                pictureBox9.Visible = false;
                pictureBox10.Visible = false;
            }
           
            
           
            /*label2.Text = charArr[0].ToString();
            label3.Text = charArr[1].ToString();
            label4.Text = charArr[2].ToString();
            label5.Text = charArr[3].ToString();
            label6.Text = charArr[4].ToString();
            label7.Text = charArr[5].ToString();
            label8.Text = charArr[6].ToString();
            label9.Text = charArr[7].ToString();
            label10.Text = charArr[8].ToString();
            label11.Text = charArr[9].ToString();*/





        }
        public static string getBetween(string strSource, string strStart, string strEnd)
        {
            if (strSource.Contains(strStart) && strSource.Contains(strEnd))
            {
                int Start, End;
                Start = strSource.IndexOf(strStart, 0) + strStart.Length;
                End = strSource.IndexOf(strEnd, Start);
                return strSource.Substring(Start, End - Start);
            }

            return "";
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }
    }
}
