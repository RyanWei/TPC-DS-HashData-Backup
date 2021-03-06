set role dsbench;
:EXPLAIN_ANALYZE
-- start query 27 in stream 1 using template query8.tpl and seed 532463799
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
                          '72687','29422','86195','84706','85956','96977',
                          '70987','59551','32902','59026','28861',
                          '12131','71385','79215','67204','66175',
                          '16377','27066','13852','75118','91423',
                          '44977','61050','80956','58137','36223',
                          '20513','79489','49736','19172','68942',
                          '95182','87259','16613','85282','23170',
                          '40678','13217','75878','74621','58409',
                          '79396','15824','47942','90905','77583',
                          '43533','46617','29376','35373','84380',
                          '45541','24273','61875','90365','42367',
                          '72476','45360','70827','31015','42100',
                          '74506','12358','88520','52466','39218',
                          '92589','79573','81327','94949','86745',
                          '31585','82870','73313','18925','46527',
                          '14271','13894','36935','95293','31574',
                          '12605','59113','29558','23225','40247',
                          '77511','44626','99668','12268','76517',
                          '84820','20044','97409','23668','83196',
                          '64311','54879','19425','63084','42222',
                          '36550','73837','49950','26691','50152',
                          '52784','51796','80635','28888','20539',
                          '24932','77770','29732','56633','83867',
                          '68475','15351','51792','95320','26466',
                          '47550','86748','15941','80363','98790',
                          '28850','21254','30545','74039','85524',
                          '82901','11283','83595','98346','45263',
                          '96128','72267','51396','11187','36737',
                          '92441','51135','34323','84632','32032',
                          '48129','81907','85447','37548','87537',
                          '32222','54617','75027','80514','50662',
                          '58983','37632','87733','94957','27720',
                          '44358','33930','85151','27757','22966',
                          '93396','21331','10463','63003','31303',
                          '88692','88342','23831','63055','21881',
                          '36814','43122','46080','33492','96397',
                          '94266','55884','59118','24471','79721',
                          '93776','92326','22597','12629','24666',
                          '50321','28196','30595','64530','16985',
                          '54421','45012','38301','95359','59990',
                          '86459','99448','59295','22277','39684',
                          '69260','81891','22924','99212','71440',
                          '94306','72853','11917','18127','70565',
                          '42900','64957','55894','89612','93025',
                          '91191','57943','87842','59241','86939',
                          '26590','84363','43725','47189','30815',
                          '75650','63986','41145','35013','44810',
                          '97930','12875','41565','74283','35134',
                          '42298','43504','62117','92190','13353',
                          '23379','96124','31848','67250','91117',
                          '10710','18976','90092','88717','86759',
                          '66024','97964','65614','75419','66853',
                          '38104','50031','75748','21971','92287',
                          '68011','85862','96926','84830','15330',
                          '39959','95062','73620','82282','68070',
                          '63191','10439','88783','55979','35043',
                          '79557','18461','66787','12057','88363',
                          '54795','93065','85327','82770','85016',
                          '51476','61595','18551','19049','75751',
                          '16407','51214','94886','92364','25268',
                          '27492','97817','16996','83499','81531',
                          '73826','35305','31344','54972','39473',
                          '12257','19348','31686','71725','37177',
                          '51127','22027','97158','68743','71391',
                          '97486','80199','52753','10296','50589',
                          '63118','74220','59429','38063','22458',
                          '50403','54003','85182','25015','47880',
                          '46530','36493','68459','23965','41911',
                          '22632','42324','75582','85108','21926',
                          '74239','90493','13324','14728','85190',
                          '92621','84710','27861','19919','95262',
                          '55069','87921','29928','56356','34507',
                          '71039','84578','89548','54526','59539',
                          '62994','37558','68897','45646','51010',
                          '59109','83345','50624','86297','19198',
                          '69277','48806','57498','48499','10906',
                          '31934','24292','74617','42184','17268',
                          '99216','44683','75036','18485','13045',
                          '78975','53145','35809','54964','97722',
                          '15523','84866','15107','61132')
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
  and d_qoy = 1 and d_year = 2002
  and (substr(s_zip,1,2) = substr(V1.ca_zip,1,2))
 group by s_store_name
 order by s_store_name
 limit 100;

-- end query 27 in stream 1 using template query8.tpl
