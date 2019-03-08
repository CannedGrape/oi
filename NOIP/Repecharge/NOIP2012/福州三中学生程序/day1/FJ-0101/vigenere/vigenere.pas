program vigenere;
var a:ansistring;
    m,k,c,q:Array[0..1000]of longint;
    i,j,n,s,t,l,lk:longint;

procedure inp;
begin
	assign(input,'vigenere.in');assign(output,'vigenere.out');reset(input);rewrite(output);
end;

procedure outp;
begin
	close(input);close(output);halt;
end;

procedure init;
begin
        readln(a);
        for i:=1 to length(a) do begin
            k[i]:=ord(a[i]);
        end;
        lk:=length(a);
        readln(a);
        for i:=1 to length(a) do begin
            m[i]:=ord(a[i]);
        end;
        l:=length(a);
        if l>lk then begin
           k[0]:=k[lk];
           for i:=lk+1 to l do k[i]:=k[i mod lk];
        end;
        for i:=1 to l do begin
            if k[i]<=90 then k[i]:=k[i]-64-1;
            if k[i]>=97 then k[i]:=k[i]-96-1;
        end;
end;

function r(u,v:longint):longint;
begin
     if u<=90 then begin
        if u-v>=65 then exit(u-v);
        if u-v<65 then begin
           v:=65-u+v;
           exit(91-v);
        end;
     end;
     if u>=97 then begin
        if u-v>=97 then exit(u-v);
        if u-v<97 then begin
           v:=97-u+v;
           exit(123-v);
        end;
     end;
end;

procedure done;
begin
     for i:=1 to l do
         write(chr(r(m[i],k[i])));
     writeln
end;

begin
     inp;
     init;
     done;
     outp;
end.
