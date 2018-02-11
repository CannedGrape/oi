program drive;
var n,x0,i,j,m,k,t:longint;
    h:Array[1..100000]of int64;
    sa,sb:int64;
    bi,minb:real;
    p,pp,num:array[1..100000,1..2]of int64;
    s,x:array[1..10000]of int64;

procedure inp;
begin
	assign(input,'drive.in');assign(output,'drive.out');reset(input);rewrite(output);
end;

procedure outp;
begin
	close(input);close(output);halt;
end;

procedure init;
begin
        readln(n);
        for i:=1 to n do read(h[i]);
        readln(x0);
        readln(m);
        for i:=1 to m do readln(s[i],x[i]);
        for i:=1 to n do
                for j:=1 to 2 do begin
                        p[i,j]:=1000000001;
                        pp[i,j]:=1000000001;
                end;
        for i:=1 to n-1 do begin
            for j:=i+1 to n do begin
                if (abs(h[j]-h[i])<p[i,1])or((abs(h[j]-h[i])=p[i,1])and(pp[i,1]>h[j])) then begin
                   p[i,2]:=p[i,1];
                   pp[i,2]:=pp[i,1];
                   p[i,1]:=abs(h[j]-h[i]);
                   pp[i,1]:=h[j];
                   num[i,2]:=num[i,1];
                   num[i,1]:=j;
                end else
                if ((abs(h[j]-h[i])<p[i,2])or((abs(h[j]-h[i])=p[i,2])and(h[j]<pp[i,2]))) then begin
                   p[i,2]:=abs(h[j]-h[i]);
                   pp[i,2]:=h[j];
                   num[i,2]:=j;
                end;
            end;
        end;
end;

procedure dri(pos,xx,who:longint);
var i,j:longint;
begin
    if ((who=1)and(xx-p[pos,2]>=0)) then begin
       sa:=sa+p[pos,2];
       dri(num[pos,2],xx-p[pos,2],2);
       if pos=0 then exit;
    end;
    if ((who=2)and(xx-p[pos,1]>=0)) then begin
       sb:=sb+p[pos,1];
       dri(num[pos,1],xx-p[pos,1],1);
       if pos=0 then exit;
    end;
end;

begin
     inp;
     init;
     minb:=1000000001/1;
     for i:=1 to n do begin
         sa:=0;sb:=0;
         dri(i,x0,1);
         if ((sa=0)and(sb=0)) then bi:=1 else
           if not ((sa=0)or(Sb=0)) then bi:=sa/sb;
         if bi<minb then begin
            t:=i;
            minb:=bi;
         end;
     end;
     writeln(t);
     for i:=1 to m do begin
         sa:=0;sb:=0;
         dri(s[i],x[i],1);
         writeln(sa,' ',sb);
     end;
     outp;
end.
