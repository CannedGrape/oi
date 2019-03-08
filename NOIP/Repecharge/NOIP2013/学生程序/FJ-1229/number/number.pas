uses math;

var n,p,i,j,temp,maxx:longint;
    a,t,f:array[1..1000001] of longint;

begin

        assign(input,'number.in');
        reset(input);
        assign(output,'number.out');
        rewrite(output);

        fillchar(t,sizeof(t),0);
        fillchar(f,sizeof(f),0);
        readln(n,p);
        for i:=1 to n do
        read(a[i]);
        readln;
        t[1]:=a[1];
        f[1]:=a[1];
        for i:=2 to n do
        begin
                temp:=a[i];
                for j:=i-1 downto 1 do
                if temp+a[j]>temp then temp:=temp+a[j];
                t[i]:=temp;
        end;
        for i:=2 to n do
        begin
                temp:=-maxlongint;
                for j:=i-1 downto 1 do
                if f[j]+t[j]>temp then temp:=f[j]+t[j];
                f[i]:=temp;
        end;
        temp:=-maxlongint;
        for i:=1 to n do
        if f[i]>temp then temp:=f[i];
        maxx:=temp;
        if maxx>0 then writeln(maxx mod p)
        else if maxx<0 then
        begin
                maxx:=abs(maxx);
                writeln('-',maxx mod p);
        end;

        close(input);
        close(output);

end.
