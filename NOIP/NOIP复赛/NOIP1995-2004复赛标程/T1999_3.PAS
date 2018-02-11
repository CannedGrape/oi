program pt1999_3(input,output);
const maxn=100;
type node=record
         num:real;
         price:real;
     end;
     arr=array[1..maxn]of node;
var oil:arr;
    pp,n,i,j,k,h,t:integer;
    ot,cs,d1,c,d2,p,sum:real;
    d:array[0..maxn] of real;
    pr:array[0..maxn]of real;
    cost:array[1..maxn+1] of real;
begin
     assign(input,'travel.in');
     reset(input);
     readln(d1,c,d2,p,n);
     for i:=1 to n do readln(d[i],pr[i]);
     close(input);
     assign(output,'travel.out');
     rewrite(output);
     d[0]:=0;d[n+1]:=d1;
     for i:=n+1 downto 1 do begin
        d[i]:=d[i]-d[i-1];
        cost[i]:=d[i]/d2;
        if cost[i]>c then begin write('No Solution');close(output);halt;end;
     end;
     oil[1].price:=p;oil[1].num:=c;sum:=oil[1].num*oil[1].price;
     i:=1;{i---the No.i gas station}
     h:=1;t:=1;
     while (i<=n) do begin
                  cs:=cost[i];
                  j:=t;{min of the prices}
{use oil }        while (j>0) and (abs(cs)>1e-6) do
                    if oil[j].num >= cs then begin
                       oil[j].num := oil[j].num-cs;cs:=0;end
                    else begin cs:=cs-oil[j].num;
                         oil[j].num :=0;
                         j:=j-1;t:=t-1;end;
{replace oil;}
                  j:=1;ot:=0;
                  while (j<=t) and (oil[j].price>pr[i]) do begin
                      ot:=ot+oil[j].num;
                      sum:=sum-oil[j].num*oil[j].price;
                      j:=j+1;
                  end;
                  if j>1 then begin                 {replacement not null}
                     h:=j-1;
                     oil[1].price:=pr[i];
                     oil[1].num:=ot+cost[i];      {add oil}
                     sum:=sum+oil[1].num*pr[i];
                     if h<>1 then
                       for k:=h+1 to t do begin
                          oil[k-(h-1)].num:=oil[k].num;
                          oil[k-(h-1)].price:=oil[k].price;
                          oil[k].num:=0;
                       end;
                     t:=t-(h-1);
                  end
                  else begin                        {replacement null}
                       for k:=t+1 downto 2 do begin
                           oil[k].num:=oil[k-1].num;
                           oil[k].price:=oil[k-1].price;
                       end;
                       t:=t+1;
                       oil[1].num:=cost[i];
                       oil[1].price:=pr[i];
                       sum:=sum+cost[i]*pr[i];
                  end;
                  i:=i+1;

     end;
               k:=t;
 {use oil }    while (k>0) and (abs(cost[n+1])>1e-6) do
                  if oil[k].num >= cost[n+1] then begin
                       oil[k].num := oil[k].num-cost[n+1];cost[n+1]:=0;end
                  else begin cost[n+1]:=cost[n+1]-oil[k].num;
                      oil[k].num :=0;k:=k-1;t:=t-1;end;

{- not used}    i:=1;
                while (i<=t) and (oil[i].num>0)  do begin
                   sum:=sum-oil[i].num*oil[i].price;
                   i:=i+1;
                end;
                writeln(sum:0:2);
                close(output);
end.
