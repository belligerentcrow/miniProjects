from discord.ext import commands
from discord.utils import get
import urllib.parse, urllib.request, re
import random
import requests
from bs4 import BeautifulSoup
import webbrowser
import discord
import io
import aiohttp

bot = commands.Bot(command_prefix=';;')
client = discord.Client()

@bot.command()
async def gimmeInfo(ctx, arg):
    #tbc
    if arg == 'Lezioni':
        await ctx.send('la prossima lezione è alle ore...')

    if arg == 'architettura':
        await ctx.send('il prof Santoro sta dormendo')

@bot.command()
async def rpgMoment(ctx, arg):  #ampliare!! magari con hps?
    if arg == 'shield':
        await ctx.send('¡EMP ACTIVATED, CABRONES!')

@bot.command()
async def cartasassoforbice(ctx, arg):
    #self explanatory. arg is either "carta", "sasso", "forbice".
    pcWeapon = random.randint(0,2)
    if(arg=='carta'):
        if(pcWeapon==0):
            await ctx.send('carta! siamo pari')
        elif(pcWeapon==1):
            await ctx.send('sasso! hai vinto tu')
        elif(pcWeapon==2):
            await ctx.send('forbice! ho vinto io')
    elif(arg=='sasso'):
        if(pcWeapon==0):
            await ctx.send('carta! ho vinto io')
        elif(pcWeapon==1):
            await ctx.send('sasso! siamo pari')
        elif(pcWeapon==2):
            await ctx.send('forbice! hai vinto tu')
    elif(arg=='forbice'):
        if(pcWeapon==0):
            await ctx.send('carta! hai vinto tu')
        if(pcWeapon==1):
            await ctx.send('sasso! ho vinto io')
        if(pcWeapon==2):
            await ctx.send('forbice! siamo pari')
    else:
        await ctx.send('Non ho capito. Per giocare a carta-sasso-forbice, scrivi ;;cartasassoforbice seguito da "carta", "sasso", o "forbice". ')


@bot.command()
async def music(ctx, arg):
    #music! searches the first result in youtube of the input, and messages the relevant link.
    #if the arg is pokelofi it generates 1 from 9 playlists of pokemon lo-fi tunes, from all 8 regions+spinoffs.
    if arg == 'pokelofi':
        shuffle = random.randint(0,8)
        if shuffle == 0:
            await ctx.send('https://www.youtube.com/watch?v=3etkGxGz-4g')
            await ctx.send('Welcome to Kanto!')
        elif shuffle == 1:
            await ctx.send('https://www.youtube.com/watch?v=KeQ9TIjOPm8')
            await ctx.send('Welcome to Johto!')
        elif shuffle == 2:
            await ctx.send('https://www.youtube.com/watch?v=I_S-yzGP36s')
            await ctx.send('Welcome to Hoenn!')
        elif shuffle == 3:
            await ctx.send('https://www.youtube.com/watch?v=6qz0SL-7U1s')
            await ctx.send('Welcome to Sinnoh!')
        elif shuffle == 4:
            await ctx.send('https://www.youtube.com/watch?v=8TM-n90qKS8')
            await ctx.send('Welcome to Unova!')
        elif shuffle == 5:
            await ctx.send('https://www.youtube.com/watch?v=pmakeVOj7js')
            await ctx.send('Welcome to Kalos!')
        elif shuffle == 6:
            await ctx.send('https://www.youtube.com/watch?v=xqi2p4W0mK4')
            await ctx.send('Welcome to Alola!')
        elif shuffle == 7:
            await ctx.send('https://www.youtube.com/watch?v=SgCx6OYgYMU')
            await ctx.send('Welcome to Galar!')
        elif shuffle == 8:
            await ctx.send('https://www.youtube.com/watch?v=rtQG7cbXA98')
            await ctx.send('Welcome to the spinoffs!')

    if arg != 'pokelofi':
        query_string = urllib.parse.urlencode({'search_query': arg})
        htm_content = urllib.request.urlopen(
            'http://www.youtube.com/results?' + query_string)
        search_results = re.findall(r'/watch\?v=(.{11})',
                                    htm_content.read().decode())
        await ctx.send('http://www.youtube.com/watch?v=' + search_results[0])

@bot.command()
async def lanciaMonetina(ctx):
    #flips a coin
        myValue = random.randint(0,1)
        if myValue == 1:
            await ctx.send('Testa')
        if myValue == 0:
            await ctx.send('Croce')

@bot.command()
async def randomWiki(ctx, lingua):
    #send a random wikipedia article. Languages avaliable: eng, ita, spa
        if lingua == 'eng':
            url = requests.get("https://en.wikipedia.org/wiki/Special:Random")
            soup = BeautifulSoup(url.content, "html.parser")
            title = soup.find(class_="firstHeading").text
            url = "https://en.wikipedia.org/wiki/%s" % title
            await ctx.send(url)
            await ctx.send('Here\'s a random page!')

        elif lingua == 'ita':
            url = requests.get("https://it.wikipedia.org/wiki/Speciale:PaginaCasuale")
            soup = BeautifulSoup(url.content, "html.parser")
            title = soup.find(class_="firstHeading").text
            url = "https://it.wikipedia.org/wiki/%s" % title
            await ctx.send(url)
            await ctx.send('Ecco una pagina casuale!')

        elif lingua == 'spa':
            url = requests.get("https://es.wikipedia.org/wiki/Especial:Aleatoria")
            soup = BeautifulSoup(url.content, "html.parser")
            title = soup.find(class_="firstHeading").text
            url = "https://es.wikipedia.org/wiki/%s" % title
            await ctx.send(url)
            await ctx.send('¡Aquí hay una página aleatoria!')

@bot.command()
async def f(ctx):
    await ctx.send('🇫')
    await ctx.send('🇫')
    await ctx.send('🇫')

@bot.command()
async def meme(ctx, arg):
    if arg == 'pepesilvia':
        await ctx.send('https://i.kym-cdn.com/entries/icons/original/000/022/524/tumblr_o16n2kBlpX1ta3qyvo1_1280.jpg')
    if arg == 'stonks':
        await ctx.send('https://www.icbz4.it/alunnifermi/wp-content/uploads/2019/12/significato-stonks-1024x766.jpg')
    if arg == 'andThenIDidnt':
        await ctx.send('https://i.pinimg.com/originals/66/41/85/664185da09f4ce15f89e8e67e2a2beac.jpg')


@bot.command()
async def info(ctx):  #context, how the command was executed
    await ctx.send(ctx.guild)
    await ctx.send(ctx.author)
    await ctx.send(ctx.message.id)

bot.run('ODk2MTQ2MzA0NDgzMzQ4NTIw.YWC3SA.NlAh_NndnsaERTKdUVejMnz6XIw')
