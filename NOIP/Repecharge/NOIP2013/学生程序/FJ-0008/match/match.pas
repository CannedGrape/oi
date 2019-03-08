var  n,i,j,sum,s,s1:longint;a,b,b1,b2,c1,c2:array[1..100000]of longint;
procedure sort(l,r: longint);
      var
         i1,j1,x,y: longint;
      begin
         i1:=l;
         j1:=r;
         x:=a[(l+r) div 2];
         repeat
           while a[i1]<x do
            inc(i1);
           while x<a[j1] do
            dec(j1);
           if not(i1>j1) then
             begin
                y:=a[i1];
                a[i1]:=a[j1];
                a[j1]:=y;
                y:=b[i1];
                b[i1]:=b[j1];
                b[j1]:=y;
                inc(i1);
                j1:=j1-1;
             end;
         until i1>j1;
         if l<j1 then
           sort(l,j1);
         if i1<r then
           sort(i1,r);
      end;
begin
assign(input,'match.in');reset(input);
assign(output,'match.out');rewrite(output);
        read(n);
        for i:=1 to n do
        begin
                read(a[i]);b[i]:=i;
        end;
        sort(1,n);
        for i:=1 to n do   begin
                c1[b[i]]:=i;b1[i]:=b[i]; end;
        for i:=1 to n do
        begin
                read(a[i]);b[i]:=i;
        end;
        sort(1,n);
        for i:=1 to n do
                begin
                c2[b[i]]:=i; b2[i]:=b[i];
                end;
        for i:=1 to n do
        begin
                s:=c2[i];
                s1:=b1[s];
                if s1=i then continue;
                 sum:=(sum+s1-i)mod 99999997;
                for j:=s1 downto i+1  do
                 begin
                   b1[c1[j-1]]:=b1[c1[j-1]]+1;
                   c1[j]:=c1[j-1];
                 end;
        end;
        write(sum);
close(input);close(output);
end.
