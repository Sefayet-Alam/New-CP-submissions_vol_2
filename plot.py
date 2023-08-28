import requests

def google_search(query):
    """Performs a Google search for the given query."""

    url = "https://www.google.com/search?q=" + query
    response = requests.get(url)
    if response.status_code == 200:
        return response.text
    else:
        raise Exception("Error searching Google: " + response.status_code)

def main():
    query = input("What do you want to search for? ")
    print(google_search(query))

if __name__ == "__main__":
    main()
