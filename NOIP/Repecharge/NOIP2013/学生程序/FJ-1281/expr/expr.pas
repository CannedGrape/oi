var s,s2,s1:string;
    len,lenb,lena,t1,t2,t3,sum:int64;
    i,j,d,tot:longint;
    a:array[1..10000000] of int64;
begin
assign(input,'expr.in');reset(input);
assign(output,'expr.out');rewrite(output);
readln(s);
len:=length(s);
for i:=1 to len do
        begin
                if s[i]='*' then
                        begin
                              j:=i;
                              while (s[j]<>'*') and (s[j]<>'+') do inc(j);
                              s1:=copy(s,i,j-i-1);
                              d:=i;
                              while (s[d]<>'*') and (s[d]<>'+') do dec(d);
                              s2:=copy(s,d,i-d-1);
                              val(s1,t1);
                              val(s2,t2);
                              t3:=t1*t2;
                              a[i]:=t3;
                              inc(tot);
                        end;
                if s[i]='+' then
                        begin
                             j:=i;
                              while (s[j]<>'*') and (s[j]<>'+') do inc(j);
                              s1:=copy(s,i,j-i-1);
                              d:=i;
                              while (s[d]<>'*') and (s[d]<>'+') do dec(d);
                              s2:=copy(s,d,i-d-1);
                              val(s1,t1);
                              val(s2,t2);
                              t3:=t1+t2;
                              a[i]:=t3;
                              inc(tot);
                        end;
        end;
i:=1;
while tot>0 do
        begin
                str(a[i],s1);
                str(a[i+1],s2);
                lena:=length(s1);
                lenb:=length(s2);
                s1:=copy(s1,lena-3,4);
                s2:=copy(s2,lenb-3,4);
                val(s1,t1);
                val(s2,t2);
                sum:=sum+t1+t2;
                tot:=tot-2;
                i:=i+2;
        end;
str(sum,s1);
len:=length(s1);
if len>4 then
        begin
               for i:=len-3 to len-1 do if s1[i]<>'0' then write(s1[i]);
               write(s1[len]);
        end
else writeln(sum);
close(input);close(output);
end.
