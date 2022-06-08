set role dsbench;
:EXPLAIN_ANALYZE
-- start query 63 in stream 0 using template query8.tpl and seed 2094825380
select  s_store_name
      ,sum(ss_net_profit)
 from store_sales
     ,date_dim
     ,store,
     (select ca_zip
     from (
      SELECT substr(ca_zip,1,5) ca_zip
      FROM customer_address
      WHERE substr(ca_zip,1,5) IN (
                          '79764','19100','41548','51640','23408','55987',
                          '85120','27628','14420','51171','67535',
                          '28827','81852','89776','39213','56690',
                          '28016','28866','14035','40424','90455',
                          '81398','95288','71535','38950','59165',
                          '64729','46401','52302','37146','43673',
                          '36522','31320','13018','27937','22166',
                          '59234','42504','34316','27477','39981',
                          '45613','21137','13932','72892','46079',
                          '75005','21680','59474','67192','31333',
                          '39214','35273','13805','98703','17370',
                          '18250','48245','54093','62128','14429',
                          '12999','62544','79548','40737','58217',
                          '81621','33582','66417','79058','45939',
                          '91287','59706','17560','79368','67214',
                          '55779','42663','27490','11600','11553',
                          '81584','85670','39685','62881','33511',
                          '17645','11592','17014','61797','57873',
                          '95172','78829','15510','22017','20265',
                          '24049','69676','63052','69453','89787',
                          '44145','98827','19175','37525','74909',
                          '62084','30540','34487','30918','19068',
                          '60643','30288','32701','56007','76501',
                          '46414','58463','71211','46364','34851',
                          '37408','93825','13566','21569','22315',
                          '13608','64696','82518','79273','55104',
                          '56444','12555','85091','27212','44069',
                          '77402','19217','86177','24622','13883',
                          '47085','17860','64403','89526','20234',
                          '77744','75001','68025','77014','28953',
                          '52555','44998','11936','32175','48792',
                          '55715','11259','15966','31197','74147',
                          '96788','19810','35763','55177','54434',
                          '70195','29920','30495','44384','16612',
                          '32109','27789','32857','73191','18919',
                          '27616','13825','22734','54800','29328',
                          '86846','77551','28393','27482','22496',
                          '42927','98928','59422','35154','19500',
                          '28342','51527','50150','27428','40647',
                          '91043','27458','97409','46012','37170',
                          '74335','76469','62928','39120','68812',
                          '47734','72866','76611','20368','13611',
                          '29535','18835','75495','23696','60164',
                          '45868','43237','27393','47548','30732',
                          '15748','61036','33940','96258','56662',
                          '32191','35655','51862','17872','97147',
                          '40361','18153','11234','26318','25087',
                          '76592','52550','26919','71434','34914',
                          '73462','91319','18380','13638','68577',
                          '36114','71096','35097','46391','71888',
                          '82424','17700','78970','11927','43398',
                          '46180','51415','54677','98097','83960',
                          '66729','38960','13281','85097','70358',
                          '69057','11564','38190','54209','75108',
                          '40897','52557','46344','21912','36315',
                          '95083','41776','41063','66756','17172',
                          '38829','35914','75043','22774','21395',
                          '28850','44353','22356','77085','26462',
                          '75588','43183','65886','16007','51466',
                          '18588','60215','40988','31655','96296',
                          '92310','78117','57251','65961','21447',
                          '67093','99594','87939','46538','27636',
                          '12157','55332','73129','46609','89607',
                          '33235','13744','86611','12782','57173',
                          '71375','34087','51053','44127','11320',
                          '84583','24673','77500','23999','38378',
                          '15568','19108','57802','92165','40250',
                          '89615','68329','75845','40204','46110',
                          '47683','62133','78012','64075','30146',
                          '27543','23109','74985','45012','47526',
                          '19867','79405','97204','26946','56262',
                          '66375','99587','99888','55692','14302',
                          '83882','81272','39535','16561','86519',
                          '57465','31396','30741','96288','99514',
                          '78147','10925','35891','95736','22091',
                          '20109','74174','52685','11586','74477',
                          '59344','59028','82500','69627','26549',
                          '42309','92061','41153','60447','85999',
                          '43980','64845','97749','70294','81755',
                          '33887','62325','84595','94981')
     intersect
      select ca_zip
      from (SELECT substr(ca_zip,1,5) ca_zip,count(*) cnt
            FROM customer_address, customer
            WHERE ca_address_sk = c_current_addr_sk and
                  c_preferred_cust_flag='Y'
            group by ca_zip
            having count(*) > 10)A1)A2) V1
 where ss_store_sk = s_store_sk
  and ss_sold_date_sk = d_date_sk
  and d_qoy = 2 and d_year = 1998
  and (substr(s_zip,1,2) = substr(V1.ca_zip,1,2))
 group by s_store_name
 order by s_store_name
 limit 100;

-- end query 63 in stream 0 using template query8.tpl
