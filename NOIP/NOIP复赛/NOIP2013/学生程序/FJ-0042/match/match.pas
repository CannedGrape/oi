var i,j,n,ll1,ll2,ll3,ll4,sum,ma:longint;
a,b,c,d:array[1..2,0..100001] of longint;
s,m:array[0..100001] of longint;
function min(o,p:longint):longint;
begin
        if o<p then exit(o);exit(p);
end;
procedure swap(var o,p:longint);
var t:longint;
begin
        t:=o;o:=p;p:=t;
end;
procedure kp(o,l,r:longint);
var c,d,mid:longint;
begin
        c:=l;d:=r;mid:=(l+r)>>1;
        repeat
                while(a[o,c]<a[o,mid]) do inc(c);
                while(a[o,d]>a[o,mid]) do dec(d);
                if c<=d then
                        begin
                                swap(a[o,c],a[o,d]);
                                swap(b[o,c],b[o,d]);
                                inc(c);dec(d);
                        end;
        until c>d;
        if c<r then kp(o,c,r);
        if l<d then kp(o,l,d);
end;
begin
        assign(input,'match.in');reset(input);
        assign(output,'match.out');rewrite(output);
        readln(n);
        for i:=1 to 2 do
                for j:=1 to n do
                        begin
                                read(a[i,j]);
                                b[i,j]:=j;
                        end;
        kp(1,1,n);
        kp(2,1,n);
        for i:=1 to n do
                begin
                        if b[1,i]>b[2,i] then begin c[1,i]:=1; c[2,i]:=2 end
                        else begin c[2,i]:=1;c[1,i]:=2; end;
                        s[i]:=abs(b[1,i]-b[2,i]);
                        inc(sum,s[i]);
                end;
        for i:=1 to 2 do
                for j:=1 to n do
                        begin
                                a[i,b[i,j]]:=j;
                                d[i,b[i,j]]:=c[i,j];
                        end;
        ll1:=sum;
        ma:=0;
        for i:=1 to n do
                begin
                inc(ma,m[i]);
                if d[1,i]=1 then dec(ll1,ma) else inc(ll1,ma);
                if d[1,i]=2 then begin inc(m[i+1]); dec(m[i+s[a[1,i]]+1]) end;
                end;
        ll2:=sum;ma:=0;
        for i:=1 to n do
                m[i]:=0;
        for i:=1 to n do
                begin
                 inc(ma,m[i]);
                if d[2,i]=1 then dec(ll2,ma) else inc(ll2,ma);
                if d[2,i]=2 then begin inc(m[i+1]); dec(m[i+s[a[2,i]]+1]) end;
                end;
        ll3:=sum;ma:=0;
        for i:=1 to n do
                m[i]:=0;
        for i:=n downto 1 do
                begin
                 inc(ma,m[i]);
                if d[2,i]=1 then inc(ll3,ma) else dec(ll3,ma);
                if d[2,i]=1 then begin inc(m[i-1]); dec(m[i-s[a[2,i]]-1]) end;
                end;
        ll4:=sum;ma:=0;
        for i:=1 to n do
                m[i]:=0;
        for i:=n downto 1 do
                begin
                 inc(ma,m[i]);
                if d[1,i]=1 then inc(ll4,ma) else dec(ll4,ma);
                if d[1,i]=1 then begin inc(m[i-1]); dec(m[i-s[a[1,i]]-1]) end;
                end;
        writeln(min(min(ll1,ll2),min(ll3,ll4)));
        close(input);close(output);
end.
