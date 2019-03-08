type
        fuhao=record
        wei:longint;
        zhi:boolean;
        end;
var
        s:ansistring;
        n:array[1..200000]of longint;
        f:array[0..100000]of fuhao;
        l:array[0..100000]of longint;
        pf,pn,i,j,pl,ans:integer;

procedure push(z:longint);
        begin
                inc(pl);l[pl]:=z;end;
procedure pout;
        var
                n:int64;
                z:longint;
        begin
                n:=1;
                for z:=1 to pl do n:=(n*l[z]) mod 10000;
                ans:=(ans+n) mod 10000;
                pl:=0;
        end;

begin
        assign(input,'expr.in');
        assign(output,'expr.out');
        reset(input);
        rewrite(output);
        readln(s);
        for i:=1 to length(s) do if (s[i]='+') or (s[i]='*')then begin
                inc(pf);f[pf].wei:=i;if s[i]='*'then f[pf].zhi:=true;end;
        for i:=1 to pf do val(copy(s,f[i-1].wei+1,f[i].wei-f[i-1].wei-1),n[i],j);
        pn:=pf+1;val(copy(s,f[pf].wei+1,length(s)-f[pf].wei),n[pn],j);
        //
        f[pf+1].zhi:=false;
        for i:=1 to pn do begin
                push(n[i]);
                if f[i].zhi=false then pout;
        end;
        writeln(ans);
        close(input);
        close(output);
end.

