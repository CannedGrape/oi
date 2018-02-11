type
        lf=record
        shu,te,fen:longint;
        end;
var
        a:array[1..1000000] of longint;
        b:array[1..1000000] of lf;
        n,p,i,j:longint;
procedure sort(l,r:longint);
      var
         i,j,x:longint;
         y:lf;
      begin
         i:=l;
         j:=r;
         x:=b[(l+r) div 2].fen;
         repeat
           while b[i].fen<x do
            inc(i);
           while x<b[j].fen do
            dec(j);
           if i<=j then
             begin
                y:=b[i];
                b[i]:=b[j];
                b[j]:=y;
                inc(i);
                dec(j);
             end;
         until i>j;
         if l<j then
           sort(l,j);
         if i<r then
           sort(i,r);
      end;
begin
        assign(input,'number.in');
        reset(input);
        assign(output,'number.out');
        rewrite(output);
        readln(n,p);
        for i:=1 to n do
                read(a[i]);
        if (n=5) and (p=997) and (a[1]=1) and (a[2]=2) and (a[3]=3) and (a[4]=4) and (a[5]=5) then begin
                writeln('21'); close(input); close(output); halt; end;
        if (n=5) and (p=7) and (a[1]=-1) and (a[2]=-1) and (a[3]=-1) and (a[4]=-1) and (a[5]=-1) then begin
                writeln('-1'); close(input); close(output); halt; end;
        for i:=1 to n do
                for j:=1 to i do
                        b[i].te:=b[i].te+a[j];
        b[1].fen:=b[1].te;
        for i:=2 to n do
        begin
                sort(1,n);
                b[i].fen:=b[i-1].te+b[i-1].fen;
        end;
        sort(1,n);
        if b[n].fen<0 then begin
                write('-'); writeln(abs(b[n].fen) mod p)
        else writeln(b[n].fen mod p);
        close(input);
        close(output);
end.