using HtmlAgilityPack;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace RGR_DOT
{
    public partial class PlantsParser : Form
    {
        bool Updating = false;
        public PlantsParser()
        {
            InitializeComponent();
        }

        private void plantBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.plantBindingSource.EndEdit();
            this.tableAdapterManager.UpdateAll(this.plantDataSet);

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'plantDataSet.Plant' table. You can move, or remove it, as needed.
            this.plantTableAdapter.Fill(this.plantDataSet.Plant);
        }




        void Parsing()
        {
            Task.Run(()=>
            {
                try
                {
                    var htmlNodes = Parse_as_SelectNodes(@"http://procweti.ru/kategorii.php"
                                                                , ".//div[@class='wrapper content']" +
                                                                  "//div[@id='right-col']" +
                                                                  "//div[@class='js_shop_list shop_list']" +
                                                                  "//div[@class='shop_cat_link']" +
                                                                  "//a"
                                                              );
                    foreach (var item in htmlNodes)
                    {
                        Match match = Regex.Match(item.OuterHtml, @".*?href=""(.*?)"".*?");

                        //richTextBox1.Text += match.Groups[1].Value;

                        var htmlPlantCategory = Parse_as_SelectNode(match.Groups[1].Value
                                                                          , ".//div[@class='wrapper content']" +
                                                                            "//div[@id='right-col']" +
                                                                            "//h1"
                                                                        );

                        Match matchPlantCategory = Regex.Match(htmlPlantCategory.OuterHtml, @"<h1>(.*?)</h1>");
                        //richTextBox1.Text += "\t - " + matchPlantCategory.Groups[1].Value + "\r\n\r\n";


                        List<string> linksPagePlant = new List<string>();
                        linksPagePlant.Add(match.Groups[1].Value);
                        //------Полученная ссылка на 1 страницу Растений в данной категории

                        var htmlPlantPageLinks = Parse_as_SelectNodes(match.Groups[1].Value
                                                                          , ".//div[@class='wrapper content']" +
                                                                            "//div[@id='right-col']" +
                                                                            "//div[@class='js_shop_list shop_list']" +
                                                                            "//div[@class='block paginator']" +
                                                                            "//a"
                                                                        );

                        if (htmlPlantPageLinks != null)
                        {
                            foreach (var itemLinksPagePlant in htmlPlantPageLinks)
                            {
                                Match matchLinksPagePlant = Regex.Match(itemLinksPagePlant.OuterHtml, @".*?href=""(.*?)"".*?");

                                linksPagePlant.Add(matchLinksPagePlant.Groups[1].Value);
                            }
                        }
                        Console.WriteLine(matchPlantCategory.Groups[1].Value);


                        foreach (var itemLinksPlantCategory in linksPagePlant)
                        {
                            var htmlPlantLinks = Parse_as_SelectNodes(itemLinksPlantCategory
                                                                          , ".//div[@class='wrapper content']" +
                                                                            "//div[@id='right-col']" +
                                                                            "//div[@class='js_shop_list shop_list']" +
                                                                            "//div[@class='shop-pane']" +
                                                                            "//div[@class='js_shop shop-item shop']" +
                                                                            "//a[@class='shop-item-title']"

                                                                        );

                            foreach (var itemPlant in htmlPlantLinks)//Цикл по растениям по всем страницам категории
                            {
                                Match matchPlants = Regex.Match(itemPlant.OuterHtml, @".*?href=""(.*?)"".*?");

                                //richTextBox1.Text += "\t\t" + matchPlants.Groups[1].Value ;


                                var htmlNodesPlantName = Parse_as_SelectNode(matchPlants.Groups[1].Value
                                                                          , ".//div[@class='wrapper content']" +
                                                                            "//div[@id='right-col']" +
                                                                            "//h1"
                                                                        );
                                Match matchPlantName = Regex.Match(htmlNodesPlantName.OuterHtml, @"<h1>(.*?)</h1>");
                                //richTextBox1.Text += "\t - " + matchPlantName.Groups[1].Value + "\r\n\r\n";

                                //Латинское название, Семейство, Другие названия
                                var htmlNodesPlantINFO = Parse_as_SelectNode(matchPlants.Groups[1].Value
                                                                          , ".//div[@class='wrapper content']" +
                                                                            "//div[@id='right-col']" +
                                                                            "//div[@class='js_shop_id js_shop shop shop_id shop-item-container']" +
                                                                            "//div[@class='shop_text']"
                                                                        );

                                //Латинское название
                                Match matchPlantLatinicName = Regex.Match(htmlNodesPlantINFO.OuterHtml, @".*?<p><u>Латинское название:</u> (.*?).</p>.*?");
                                //richTextBox1.Text += "\t\t\t" + matchPlantLatinicName.Groups[1].Value + "\r\n";

                                //Семейство
                                Match matchPlantFamily = Regex.Match(htmlNodesPlantINFO.OuterHtml, @".*?<p><u>Семейство:</u> (.*?).</p>.*?");
                                //richTextBox1.Text += "\t\t\t" + matchPlantFamily.Groups[1].Value + "\r\n";

                                //Другие названия
                                Match matchPlantAnotherName = Regex.Match(htmlNodesPlantINFO.OuterHtml, @".*?<p><u>Другие названия:</u> (.*?).</p>.*?");
                                //richTextBox1.Text += "\t\t\t" + matchPlantAnotherName.Groups[1].Value + "\r\n";

                                MatchCollection collectionDescription = Regex.Matches(htmlNodesPlantINFO.OuterHtml, @"<p>(.*?)</p>");

                                string description = "";
                                foreach (Match itemDescription in collectionDescription)
                                {
                                    string partDesc = itemDescription.Groups[1].Value;
                                    if (partDesc.IndexOf("<u>") == -1)
                                    {
                                        partDesc.Replace("<p>", "\t");
                                        partDesc.Replace("</p>", "");
                                        description += partDesc;
                                    }
                                }

                                Invoke((MethodInvoker)delegate
                                {
                                    var Row = plantDataSet.Plant.NewRow();


                                    Row["Name"] = matchPlantName.Groups[1].Value;
                                    Row["Category"] = matchPlantCategory.Groups[1].Value;
                                    Row["LatinName"] = matchPlantLatinicName.Groups[1].Value;
                                    Row["Family"] = matchPlantFamily.Groups[1].Value;
                                    Row["AnotherName"] = matchPlantAnotherName.Groups[1].Value;
                                    Row["URL"] = matchPlants.Groups[1].Value;

                                    if (plantDataSet.Plant.Select("Name='" + Row["Name"] + "'").Length == 0)
                                    {
                                        plantDataSet.Plant.Rows.Add(Row);
                                        plantTableAdapter.Update(plantDataSet.Plant);
                                        plantDataSet.AcceptChanges();
                                        plantDataGridView.DataSource = plantBindingSource;
                                    }
                                });
                            }
                        }

                    }
                    MessageBox.Show("Окончание Парсинга","Паринг сайта");
                    Updating = false;
                }
                catch (Exception ex)
                {
                    Console.WriteLine("What's wrong. {Exception}");
                }
            });

           
        }

        static HtmlNode Parse_as_SelectNode(string url, string xPathExpressoin)
        {
            var pageContent = LoadPage(url);

            var document = new HtmlAgilityPack.HtmlDocument();
            document.LoadHtml(pageContent);
            var answer = document.DocumentNode.SelectSingleNode(xPathExpressoin);

            return answer;
        }


        static HtmlNodeCollection Parse_as_SelectNodes(string url, string xPathExpressoin)
        {
            var pageContent = LoadPage(url);

            var document = new HtmlAgilityPack.HtmlDocument();
            document.LoadHtml(pageContent);
            var answer = (document.DocumentNode.SelectNodes(xPathExpressoin) ?? Enumerable.Empty<HtmlNode>()) as HtmlNodeCollection;

            return answer;
        }

        static string LoadPage(string url)
        {
            var result = "";
            var request = (HttpWebRequest)WebRequest.Create(url);
            var response = (HttpWebResponse)request.GetResponse();

            if (response.StatusCode == HttpStatusCode.OK)
            {
                var receiveStream = response.GetResponseStream();
                if (receiveStream != null)
                {
                    StreamReader readStream;
                    if (response.CharacterSet == null)
                        readStream = new StreamReader(receiveStream);
                    else
                        readStream = new StreamReader(receiveStream, Encoding.GetEncoding(response.CharacterSet));
                    result = readStream.ReadToEnd();
                    readStream.Close();
                }
                response.Close();
            }


            /*HtmlWeb webDoc = new HtmlWeb();
            HtmlDocument doc = webDoc.Load("http://www.cnshb.ru/AKDiL/cards/");

            HtmlNodeCollection nodes = doc.DocumentNode.SelectNodes("//meta[@http-equiv]");

            Match match = Regex.Match(nodes[0].OuterHtml.ToString(),@".*?charset=(.*?)"">");
            
            Console.WriteLine(nodes[0].OuterHtml.ToString());           

            Encoding src = Encoding.GetEncoding(match.Groups[1].Value.ToString()); 
            Encoding utf = Encoding.UTF8;

            byte[] srcArr = utf.GetBytes(result);
            byte[] utfArr = Encoding.Convert(src, utf, srcArr);
            */

            result.Replace('\r', (char)0);
            result.Replace('\n', (char)0);

            return result;
        }

       

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (!Updating)
            {
                Task.Run(() =>
              {
                  MessageBox.Show("Обновление данных, это может занять до 5 минут. При завершении будет послано уведомление.", "Паринг сайта");
              });
                Updating = true;
                Parsing();
            }
            else
                Task.Run(() =>
                {
                    MessageBox.Show("Обновление уже просиходит", "Паринг сайта");
                });
        }

        private void toolStripButtonEdit_Click(object sender, EventArgs e)
        {
            if (plantDataGridView.SelectedRows.Count > 0)
            {
                var plant = new PlantForm(plantDataGridView.SelectedCells[0].RowIndex);
                plant.ShowDialog();

                this.plantTableAdapter.Fill(this.plantDataSet.Plant);
            }
        }

        private void bindingNavigatorDeleteItem_Click(object sender, EventArgs e)
        {
            var rowIndex = this.plantDataGridView.SelectedCells[0].RowIndex;

            plantDataGridView.Rows.RemoveAt(rowIndex);
            plantDataSet.Tables["Plant"].Rows[rowIndex].Delete();
            plantTableAdapter.Update(plantDataSet);
        }

        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {
        }

        private void toolStripButtonAdd_Click(object sender, EventArgs e)
        {
            var bank = new PlantForm();
            bank.ShowDialog();
            this.plantTableAdapter.Fill(this.plantDataSet.Plant);
        }

        private void toolStripButton4_Click(object sender, EventArgs e)
        {
            var rowIndex = this.plantDataGridView.SelectedCells[0].RowIndex;

            plantDataGridView.Rows.RemoveAt(rowIndex);
            plantDataSet.Tables["Plant"].Rows[rowIndex].Delete();
            plantTableAdapter.Update(plantDataSet);
        }
    }
}
