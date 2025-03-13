import Data.Set (fromList, toList)

-- Nome: Cleverson Pereira da Silva - TIA: 32198531
-- Professor: Antonio Luiz Basile
-- Turma: [05N]

del_rep :: Ord a => [a] -> [a]
del_rep = toList . fromList

main :: IO ()
main = do
    let lista = [3,1,2,1,2,3]
    let nova_lista = del_rep lista
    print nova_lista
